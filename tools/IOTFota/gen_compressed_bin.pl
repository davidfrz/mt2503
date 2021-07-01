 #!/usr/bin/perl
use tools::zImageProcess;
use File::Copy;
use File::Path;


# @ARGV[0] : binary need to compressed
# @ARGV[1] : raw binary backup
# @ARGV[2] : ini
my $binaryContent = @ARGV[0];
my $outputFolder=  @ARGV[1];
my $outputPrefix=  @ARGV[2];
my $decompressStartAddress = 0x00000032;
my $partitions = [{"ratio" => [1], "type" => 0}];
my $tmpFolder = "@ARGV[1]\\FUNET";

my $binarySize = -s $binaryContent;
# This size need sync with tools/scatGenBL.pl 
# Need <= than $IOT_IMAGE_BUFFER_SIZE 
my $splitBinSize = 256000;   
my $buffer;
my $compressed;

open INPUT, '<', @ARGV[3] or die "open failed: $!\n";
foreach $line (<INPUT>)
{
	
	if( !($line =~ m/#/))
	{
		if ($line =~ m/COMPRESSED /i && $line =~ m/true/i)
		{
			$compressed =  true;
		}		
	}
}

if($compressed)
{
		open INF,$binaryContent
			 or die "\nCan't open $binaryContent for reading: $!\n";	 	 
		binmode INF;

		my $splitNum = 0;
		my $j = 0;
		rmtree($tmpFolder);

		unless(mkdir $tmpFolder) {
		die "Unable to create $tmpFolder";
		}
		
		#1.split binary into 256k Trunk
		while (read (INF, $buffer, $splitBinSize)	) 
		{
			open OUTF,"+>","$tmpFolder\\$splitNum"
				or die "\nCan't open $splitNum  for reading: $!\n";	 
			binmode OUTF;
			print OUTF $buffer;
			close OUTF;
			$splitNum++;
		};

		close INF;
		  
		#2. compressed binary for each 512K trunk
		while($j < $splitNum)
		{
			&zImageProcess::CompressByPartition(
			"$tmpFolder\\$j", 
			"$tmpFolder\\$j.tmp", 
			undef, 
			$decompressStartAddress,
			$partitions
			);
			unlink("$tmpFolder\\$j.tmp");
			$j++;
		}


		#3.Make x byte Header  
		#struct compressed_header  // 96 byte
		#{
		#u32 compressed magic
		#u32 raw_img_size
		#u32 img_number
		#u32 reserved
		#u32 [20] img_size
		#}
		open OUTF,"+>","$tmpFolder\\header"
			or die "\nCan't open $splitNum for reading: $!\n";	 
		binmode OUTF;
		my $magic_num = 0xCa1234b7;
		print OUTF pack('llll',$magic_num,$binarySize,$splitNum,0); #img_number
		$j = 0;

		while($j < 20)
		{
			if($j < $splitNum)
			{
				$binarySize = -s "$tmpFolder//$j";
				print "size: $binarySize";
				print OUTF pack('l',$binarySize); #img_number
			}else{
				print OUTF pack('l',0); #img_number
			}
			$j++;
		}

		close OUTF;

		#4.Composed header and each trunk
		copy("$tmpFolder\\header", "$tmpFolder\\compressed.bin");
		open OUTF,">>","$tmpFolder\\compressed.bin"
			 or die "\nCan't open $binaryContent for reading: $!\n";	 	 
		binmode OUTF;
		$j = 0;
		while($j < $splitNum)
		{
			open INF,"$tmpFolder//$j"
			 or die "\nCan't open $binaryContent for reading: $!\n";	 	 
			binmode INF;
			$binarySize = -s "$tmpFolder//$j";
			read (INF, $buffer, $binarySize);	
			print OUTF $buffer;
			$j++;
			close INF;
		}
		
		close OUTF;
		copy("$tmpFolder\\compressed.bin", "$outputFolder\\$outputPrefix"._."compressed.bin");
}