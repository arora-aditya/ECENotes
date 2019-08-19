directory=../section

watch:
	nodemon -e md,css --exec "make all"
# The all rule makes all the PDF files listed
all : build

build:
	# rm -rf "$(directory)"
	mkdir -p "$(directory)"
	sh build.sh

# Remove all PDF outputs then build them again
rebuild : all
