directory=../output

watch:
	nodemon -e md,css,html --exec "make all"
# The all rule makes all the PDF files listed
all : build

build:
	mkdir -p "$(directory)"
	sh build.sh

%.html: %.md
	mkdir -p $(directory)/$(*F)
	pandoc $(*F).md --toc --strip-comments -c pandoc.css --wrap=preserve --katex -s -o $(directory)/$(*F)/index.html -H head.html -A button.html --toc-depth=6
	cp pandoc.css $(directory)/$(*F)/

# Remove all PDF outputs then build them again
rebuild : all