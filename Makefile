all: *
	make tex
	make pdf
	$(MAKE) -C tests
	make clean

pdf: notebook.tex
	latexmk --pdf notebook.tex

tex: code/* latex/*
	python latex/latex.py > notebook.tex

clean:
	rm *.aux *.log *.toc *.out *.fls *.fdb_latexmk
