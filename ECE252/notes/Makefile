# List files to be made by finding all *.md files and appending .html
PDFS := $(patsubst %.tex,%.html,$(wildcard *.tex))
pwd=$(shell pwd)
directory=../output

watch:
	nodemon -e html,png,tex,css,md --exec "make all"
# The all rule makes all the PDF files listed
all : directory README.html SAMPLE_CODE.html

directory:
	mkdir -p "$(directory)"
	cp pandoc.css "$(directory)/pandoc.css"
	cp -r images/ "$(directory)/images"
# This generic rule accepts PDF targets with corresponding Markdown
# source, and makes them using pandoc
%.html : %.tex
	pandoc $< -c pandoc.css --wrap=preserve --toc --wrap=preserve --katex -s -o "$(directory)/$@" -H head.html -A button.html --toc-depth=6 --metadata pagetitle="$@"

%.html : %.md
	pandoc $< -c pandoc.css --wrap=preserve --toc --wrap=preserve --katex -s -o "$(directory)/$@" -H head.html --toc-depth=6 --metadata pagetitle="$@"


rebuild : all
