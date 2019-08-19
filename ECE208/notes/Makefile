# List files to be made by finding all *.md files and appending .html
directory=../output

watch:
	nodemon -e md,css --exec "make all"
# The all rule makes all the PDF files listed
all : build

build:
	mkdir -p "$(directory)"
	sh build.sh

# Remove all PDF outputs then build them again
rebuild : all
