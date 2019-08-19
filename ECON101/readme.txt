REGEX replacements

^Answer: ([A-E])
\n\n\n---\n---\nAnswer: <sub><sub>$1<sub><sub>\n\n

^(\d\d*.\d)
## $1

PANDOC build command
pandoc parkin_8e_TIF_ch10.docx -o README.md --extract-media=.

MARKDOWN TO PDF
pandoc README.md -o 14.pdf -V geometry:"top=2cm, bottom=1.5cm, left=1cm, right=1cm"
