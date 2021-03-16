#!/usr/bin/perl
use warnings;
use strict;
die "program x y density" unless (scalar(@ARGV) == 3);
my $one = "1";
my $two = "2";
my $three = "3";
my ($x, $y, $density) = @ARGV;
print "$y$one$two$three\n";
for (my $i = 0; $i < $y; $i++) {
	for (my $j = 0; $j < $x; $j++) {
		if (int(rand($y) * 2) < $density) {
			print "2";
		}
		else {
			print "1";
		}
	}
	print "\n";
}
