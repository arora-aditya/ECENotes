# List files to be made by finding all *.md files and appending .html
PDFS := $(patsubst %.md,%.html,$(wildcard *.md))
pwd=$(shell pwd)
directory=../output

watch:
	nodemon -e md,css --exec "make all"
# The all rule makes all the PDF files listed
all : directory $(PDFS)

directory:
	mkdir -p "$(directory)"
# This generic rule accepts PDF targets with corresponding Markdown
# source, and makes them using pandoc
%.html : %.md
	pandoc $< --toc --wrap=preserve --katex -s -o "$(directory)/$@" -H head.html --toc-depth=6

# Remove all PDF outputs then build them again
rebuild : all
