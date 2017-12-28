code_dir = "code/"
template_file = "latex/template.tex"
contents_file = "latex/contents.txt"

# return file string
def readFile(filename):
	f = open(filename, "r")
	contests =  f.read()
	f.close()
	return contests

def getSections():
	global contents_file
	index = open(contents_file, "r")
	sections = []

	cur_section = []
	for line in index:
		if len(line) == 1 or line[0] == '#':
			pass
		elif line[0] == '[':
			if len(cur_section) > 0:
				sections.append(cur_section)
			section_name = line[1:-2]
			cur_section = [section_name, []]
		else:
			cur_section[1].append(line[0:-1].split(';'))
	if len(cur_section) > 0:
		sections.append(cur_section)
	return sections

def finishLatex(contents):
	return contests

def getLanguage(filename):
	extension = filename.split('.')[-1]
	if extension == "cpp":
		return "C++"
	else:
		return ""

sections = getSections()

latex = ""
template = open(template_file, "r")

for line in template:
	if line[0:-1] == "#add here":
		for section in sections:
			latex += "\\section{" + section[0] + "}\n"
			for subsection in section[1]:
				latex += "\\subsection{" + subsection[1] + "}\n"
				latex += "\\begin{lstlisting}[language="+getLanguage(subsection[0])+"]\n" + readFile(code_dir + subsection[0]) + "\\end{lstlisting}\n"
	else:
		latex += line

print(latex)
template.close()
