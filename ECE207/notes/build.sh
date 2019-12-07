directory="../section"
for file in *.md
do
    dir="${file%.md}"
    mkdir -p "$directory/$dir"
    pandoc $file --toc --strip-comments -c pandoc.css --wrap=preserve --katex -s -o "$directory/$dir/index.html" -H head.html --toc-depth=6
    cp pandoc.css "$directory/$dir/pandoc.css"
done
