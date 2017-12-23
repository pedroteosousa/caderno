caderno: * code/*
	python generator/generate.py > caderno.tex
	pdflatex caderno.tex
	pdflatex caderno.tex

clean:
	rm caderno.aux caderno.log caderno.toc
