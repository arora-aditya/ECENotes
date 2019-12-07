for file in *.md
do
    dir="${file%.md}"
    mkdir -p "../output/$dir"
    pandoc $file --toc --strip-comments -c pandoc.css --wrap=preserve --katex -s -o "../output/$dir/index.html" -H head.html -A button.html --toc-depth=6
    cp pandoc.css "../output/$dir/pandoc.css"
done
