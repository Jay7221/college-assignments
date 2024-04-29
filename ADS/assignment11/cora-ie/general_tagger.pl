#!/usr/bin/perl -w

########################################################
# General data tagger
#
# Kristie Seymore, 5/13/99
# 
#
# Parts of this code have been borrowed directly from
# the Perl/Tk widgets demonstration...
#
# IMPORTANT!!!! Create an input directory, and copy the
# files to be tagged to this directory. Do not use your
# original and unique copies of the files to be tagged with this 
# program, as you risk accidentally deleting them with the
# 'Skip' button.
#
# TO START:
# Put the files you want to tag into the <input_dir>,
# create a directory to hold the tagged files <output_dir>,
# and create a file <label_file> containing a list of the tags you
# want to use.  You can change the input and output directory
# if necessary during tagging. (IMPORTANT: Create a backup of the files you
# are going to tag - it is possible to delete them during tagging
# with the 'Skip' button, which is useful only if that's what
# you meant to do!!!)
#
# TO TAG:
# Click on the 'Next File' button to bring up the first file.
# Select a tag from the list on the left by clicking on it.
# Use the first mouse button to highlight the text you want
# to tag. Use the third mouse button to apply the tag. The
# second mouse button will remove any tags from the highlighted text.
#
# TO CHANGE FILES:
# 'Next File': saves the current file (with any tags)
# 	to the output directory, and then loads the next file from the
# 	input directory.
# 'Previous File': loads the previous file.
# 
# In both cases (next file and previous file), the script will
# first look in the output directory to see if a tagged
# version of the file already exists. If it does, this copy will
# be loaded.
#
# 'Cut': delete the text after the current cursor position
# 'Skip': delete the file from the input directory (yes, DELETE!!)
# 	This way, the file will not show up as you scroll forward and
#	backwards through your files with the 'Next' and 'Previous' buttons.
# 'Quit': exit the tagging program
########################################################

require 5.004;

use Tk;
use Tk::BrowseEntry;
use Tk::Dialog;

if ($#ARGV < 2) {
    die "\nUsage: general_tagger.pl <input_dir> <output_dir> <label_file>\n\nIMPORTANT: This script enables you to delete files in the input directory\nwith the Skip button. Create a backup now!!\n\n";
}
else {
    $intextfiledir = "${ARGV[0]}/";
    $outtextfiledir = "${ARGV[1]}/";
    $labelfile = $ARGV[2];
}

(@infilelist) = read_filelist($intextfiledir);
($label_width, @labels) = read_labels($labelfile);

my $num_labels = $#labels + 1;
my $current_start = "0.0";
my $current_end = "0.0";
my $text_start = "0.0";
my $text_end = "0.0";

$current_file = "";
$fileonly = "";
$index = -1;
$num_files = $#infilelist + 1;
$done = $index + 1;

# Create main window
$mw = MainWindow->new;
$mw->title('Text Tagger');

# Define font classes
my $size = -18;
$mw->fontCreate('C_normal',-family => 'courier', -size => $size);
$mw->fontCreate('C_small',-family => 'courier', -size => int(12*$size/14));
$mw->fontCreate('C_bold',-family => 'courier', -weight => 'bold', -size => $size);
$mw->fontCreate('C_big',-family => 'courier', -weight => 'bold', -size => int($size*18/14));
$mw->fontCreate('C_vbig',-family => 'helvetica', -weight => 'bold', -size => int($size*24/14));

# Create frame for label and entry frames
my $labent = $mw->Frame;

# Create label frame
my $labelframe = $labent->Frame;
my $textlabel = $labelframe->Label(-text => "Text Directory: ",
                      -anchor => 'e');
my $taggedlabel = $labelframe->Label(-text => "Tagged Directory: ",
                      -anchor => 'e');
my $filelabel = $labelframe->Label(-text => "Current File: ", -anchor => 'e');
$textlabel->pack;
$taggedlabel->pack;
$filelabel->pack;
$labelframe->pack(-side => 'left');


# Create entry frame
my $entryframe = $labent->Frame;
my $textentry = $entryframe->Entry(-width => '80',
                      -textvariable => \$intextfiledir);
my $taggedentry = $entryframe->Entry(-width => '80',
                      -textvariable => \$outtextfiledir);
my $fileentry = $entryframe->Entry(-width => '80',
                      -textvariable => \$fileonly);
$textentry->pack;
$taggedentry->pack;
$fileentry->pack;
$entryframe->pack(-side => 'left');

# Create record frame
my $recordframe = $labent->Frame;
my $recordlabel = $recordframe->Label(-text => "$done of $num_files files",
                      -anchor => 's');
$recordlabel->pack(-side => 'bottom');
$recordframe->pack(-side => 'left');


# Pack the labels and entries in the right order
$labent->pack(-side => 'top');


$textentry->bind('<Return>', sub {
                                $intextfiledir = $textentry->get;
                                print "Input dir = $intextfiledir\n";
                                undef(@infilelist);
				(@infilelist) = read_filelist($intextfiledir);
				$current_file = "";
				$fileonly = "";
				$index = -1;
                                $done = $index + 1;
                                $num_files = $#infilelist + 1;
                             } );

$taggedentry->bind('<Return>', sub {
                                $outtextfiledir = $taggedentry->get;
                                print "Output dir = $outtextfiledir\n";
                             } );


# Fancy list box (actually a text widget)
my $fancylist = $mw->Text(
        -font => 'C_bold',
   	-relief => 'sunken',
 	-width => $label_width,
	-height => $num_labels)->pack(-side => 'left');
$fancylist->tagConfigure('red', foreground => 'red');
$fancylist->tagConfigure('raise', background => 'yellow');

$fancylist->bind('<1>', sub { 
                              $fancylist->tagRemove('raise', $current_start, $current_end);
                              $current_start = $fancylist->index('insert linestart');
                              $current_end = $fancylist->index('insert lineend');
                              $fancylist->tagAdd('raise', $current_start, $current_end);

                              $current_tag = $fancylist->get($current_start, $current_end);
                              # print "Current tag = $current_tag\n";
                        } );

foreach $label (@labels) {
    $fancylist->insert('end', "$label\n");
}

# Create scroll bar text widget inside main window
my $text = $mw->Scrolled('Text',
 	-font => 'C_bold',
    	-scrollbars => 'oe',
    	-wrap       => 'word',
    	-width      => 80,
    	-height     => 30)->pack(-expand => 'yes', -fill => 'both');
$text->tagConfigure('red', foreground => 'red');
$text->tagConfigure('sel', foreground => 'blue', background => 'white');
$text->tagConfigure('yellow', foreground => 'yellow');

$text->bind('<Button1-ButtonRelease>', sub { 
                                             $text_start = $text->index('insert');
                                             $text_end = $text->index('current'); 
                                             $selected_text = $text->get($text_start, $text_end);
                                             # print "selected text = $selected_text\n"; 
                                        } );

# Tag selected text
$text->bind("<3>" , sub {
                        $text->delete($text_start, $text_end);
                        &tag_text($current_tag);
                   } );

# Untag selected text
$text->bind("<2>", sub { &untag_text; } );


# Create button frame
my $buttonframe = $mw->Frame;


my $next_button = $buttonframe->Button(
    -text => 'Next File',
    -command => [\&load_next_file, $text, \$current_file, \$fileonly, \$index, \@infilelist, \$outtextfiledir, 0]);

my $previous_button = $buttonframe->Button(
    -text => 'Previous File',
    -command => [\&load_previous_file, $text, \$current_file, \$fileonly, \$index, \@infilelist, \$outtextfiledir, 0]);

my $cut_button = $buttonframe->Button(
    -text => 'Cut',
    -command => sub { $text->delete('insert', 'end'); } );

my $skip_button = $buttonframe->Button(
    -text => 'Skip',
    -command => sub { @infilelist = remove_file($text, \$current_file, \$fileonly, \$index, \@infilelist, \$outtextfiledir); } );

my $dismiss = $buttonframe->Button(
    -text    => 'Quit',
    -command => [$mw => 'destroy']);

$next_button->pack(qw/-side left -pady 5 -padx 10/);
$previous_button->pack(qw/-side left -pady 5 -padx 10/);
$cut_button->pack(-side => 'left', -pady => '5', -padx => '10');
$skip_button->pack(-side => 'left', -pady => '5', -padx => '10');
$dismiss->pack(qw/-side left -pady 5 -padx 10/);
$buttonframe->pack;

MainLoop;


sub load_next_file {

    my ($window, $r_file, $r_fileonly, $r_index, $ra_infilelist, $r_outtextfiledir, $skip) = @_;

    if (!$skip) {
        # Print out current file to output directory

        if ($$r_file =~ /\w/) {
            my $tagged_text = $text->get('1.0', 'end');
            &clean_tagged_text(\$tagged_text);
            &print_file($r_fileonly, $$r_outtextfiledir, \$tagged_text);
        }
    }

    $window->delete(qw/1.0 end/);

    # Get next filename in list
    if ($$r_index < $#$ra_infilelist) {
        $$r_index++;
        $$r_file = $ra_infilelist->[$$r_index];
    }
    else {
        $$r_file = "";
        if ($$r_index == $#$ra_infilelist) {
            $$r_index++;
            $done++;
        } 
        $mw->Dialog(
            -title  => 'End',
            -text   => 'END OF FILE LIST',
        )->Show;
        return;
    }

    &read_file($window, $r_file, $r_fileonly, $$r_outtextfiledir);
    $done++;
    $recordlabel->configure(text => "$done of $num_files files");

} # end load_next_file


sub load_previous_file {

    my ($window, $r_file, $r_fileonly, $r_index, $ra_infilelist, $r_outtextfiledir, $skip) = @_;

    # Print out current file to output directory
    if (!$skip) {
        if ($$r_file =~ /\w/) {
            my $tagged_text = $text->get('1.0', 'end');
            &clean_tagged_text(\$tagged_text);
            &print_file($r_fileonly, $$r_outtextfiledir, \$tagged_text);
        }
    }
    $window->delete(qw/1.0 end/);

    # Get next filename in list
    if ($$r_index <= 0) {
        $$r_file = "";
        if ($$r_index == 0) {
            $$r_index--;
            $done--;
            $recordlabel->configure(text => "$done of $num_files files");
        }
        $mw->Dialog(
            -title  => 'Begin',
            -text   => 'BEGINNING OF FILE LIST',
        )->Show;
        return;
    }
    else {
        $$r_index--;
        $$r_file = $ra_infilelist->[$$r_index];
    }

    &read_file($window, $r_file, $r_fileonly, $$r_outtextfiledir);
    $done--;
    $recordlabel->configure(text => "$done of $num_files files");

} # end load_previous_file



sub tag_text {
    my ($current_tag) = @_;
    my(@lines, @words, $start, $end, $line, $word);
    my ($tagged_text);

    $current_tag =~ s/\s+//g;
    # print "Current tag = $current_tag\n";

    # Tag beginning and ending of region
    $tagged_text = "<$current_tag> $selected_text </$current_tag>";

    $text->insert($text_start, $tagged_text, 'red');
}

sub untag_text {
    my(@lines, @words, $start, $end, $line, $word);
    my ($tagged_text);

    $text->delete($text_start, $text_end);
    $selected_text =~ s/\<.*?\>//g;
    # $selected_text =~ s/\s+/ /g;
    $selected_text =~ s/^\s+//g;
    $selected_text =~ s/\s+$//g;

    $text->insert($text_start, $selected_text);
}



sub read_file {
    my ($w, $r_file, $r_fileonly, $altdir) = @_;
    my ($file_to_read, $initial);
    my ($buf, $bytes) = ('', 0);

    $$r_fileonly = $$r_file;
    $$r_fileonly =~ s/^.*\/(.*)$/$1/;

    my $test = "${altdir}$$r_fileonly";

    # See if file already exists in output directory
    if (-e $test) {
        $file_to_read = $test;
        $initial = 0;
    }
    else {
        $file_to_read = $$r_file;
        $initial = 1;
    }

    if (not open(F, "< $file_to_read")) {
        $mw->Dialog(
            -title  => 'File Not Found',
            -text   => 'ERROR',
            -bitmap => 'error',
        )->Show;
        return;
    }

    my @all_lines = <F>;
    my $all_lines = join('',@all_lines);

    $w->insert('end', $all_lines);
    close F;
 
    # Add tags to text for display
    &add_tags($all_lines); 
}


sub clean_tagged_text {
    my ($r_tagged_text) = @_;
    my (@lines, $line, $new);
 
    (@lines) = split('\n', $$r_tagged_text);
    foreach $line (@lines) {

        # Collapse duplicate tags
        $$r_tagged_text =~ s/\<\/(.*?)\>\s+\<\1\>//g;

        $$r_tagged_text =~ s/\s+/ /g;
        $$r_tagged_text =~ s/^\s+//g;
        $$r_tagged_text =~ s/\s+$//g;

        $new .= "$line\n";
    }

    $$r_tagged_text = $new;
}


sub print_file {
    my ($r_fileonly, $outdir, $r_text) = @_;

    my $finalfile = "${outdir}$$r_fileonly";

    open(OUTF, "> $finalfile") or die "Couldn't open output file!!\n";
    print OUTF "$$r_text\n";
    close(OUTF);

}

sub read_filelist {
    my ($dir) = @_;
    my ($file, @filelist);

    open(FIND, "find $dir | ") or die "Couldn't run find...\n";
    $file = <FIND>;  # Get rid of bogus first line
    while ($file = <FIND>) {
        chop $file;

        next if ($file !~ /\w/);
        push(@filelist, $file);
    }
  
    return (@filelist);
}

sub add_tags {
    my ($all) = @_;
    my ($start, $end, $match, @matches, $string);

    # Change already tagged regions to red
    $all =~ s/\n//g;

    (@matches) = ($all =~ /\<(.*?)\>.*?\<\/\1\>/g);
    $last_match = "0.0";
    foreach $match (@matches) {
        $start = $text->search(-nocase, "<$match>", $last_match);
        if (!defined($start)) { last; }
        $last_match = $start;
        $end = $text->search(-nocase, "</$match>", $last_match);
        if (!defined($end)) { last; }
        $last_match = $end;
            
        $text->tagAdd('red', "$start wordstart", "$end wordend");

        # print "$match\n";
    }

}

sub remove_file {

    my ($text, $r_file, $r_fileonly, $r_index, $ra_infilelist, $outdir) = @_;
    my ($file, @newlist, $skip);

    my $remove_file = $$r_file;
    my $remove_fileonly = $$r_fileonly;

    $skip = 1;

    # Load next file
    &load_next_file($text, $r_file, $r_fileonly, $r_index, $ra_infilelist, $outdir, $skip);

    # Remove file from infilelist array
    undef @newlist;
    foreach $file (@$ra_infilelist) {
        next if ($file eq $remove_file);
        push @newlist, $file;
    }
    undef @$ra_infilelist;

    # Lower file counters
    $$r_index--;
    $done--;
    $num_files = $#newlist + 1;
    $recordlabel->configure(text => "$done of $num_files files");

    # Remove file from input directory
    if (-e $remove_file) {
        system "rm -f $remove_file\n";
    }

    # Remove file from output directory
    my $outfile = "$outdir/$remove_fileonly";
    if(-e $outfile) {
        system "rm -f $outfile\n";
    }

    return @newlist;

} # end remove_file


sub read_labels {
    my ($file) = @_;
    my ($line, $label_width, @labels);

    $label_width = 0;
    open(LABEL, $file) or die "Couldn't open label file $file\n";
    while ($line = <LABEL>) {
        chomp $line;

        ($label) = split(' ',$line);
        if (length($label) > $label_width) {
            $label_width = length($label);
        }
        push @labels, $label;
    }
    close(LABEL);

    return($label_width, @labels);
}

