pdf: *
	make tex
	pdflatex notebook.tex
	pdflatex notebook.tex

tex: *
	python latex/latex.py > notebook.tex

clean:
	rm notebook.aux notebook.log notebook.toc
