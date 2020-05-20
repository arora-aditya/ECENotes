for file in *.md
do
    dir="${file%.md}"
    offset="${dir//[!1-9]/}"
    mkdir -p "../output/$dir"
    pandoc $file --toc --strip-comments --number-offset=$offset -c pandoc.css --wrap=preserve --katex -s -o "../output/$dir/index.html" -H head.html -A button.html --toc-depth=6
    cp pandoc.css "../output/$dir/pandoc.css"
done