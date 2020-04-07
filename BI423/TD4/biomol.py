comp = {"A":"T","T":"A","C":"G","G":"C"}
trans = {
	"U":{
		"U":{
			"U":"F",
			"C":"F",
			"A":"L",
			"G":"L"
		},
		"C":{
			"U":"S",
			"C":"S",
			"A":"S",
			"G":"S"
		},
		"A":{
			"U":"Y",
			"C":"Y",
			"A":"*",
			"G":"*"
		},
		"G":{
			"U":"C",
			"C":"C",
			"A":"*",
			"G":"W"
		}
	},
	"C":{
		"U":{
			"U":"L",
			"C":"L",
			"A":"L",
			"G":"L"
		},
		"C":{
			"U":"P",
			"C":"P",
			"A":"P",
			"G":"P"
		},
		"A":{
			"U":"H",
			"C":"H",
			"A":"Q",
			"G":"Q"
		},
		"G":{
			"U":"R",
			"C":"R",
			"A":"R",
			"G":"R"
		}
	},
	"A":{
		"U":{
			"U":"I",
			"C":"I",
			"A":"I",
			"G":"M"
		},
		"C":{
			"U":"T",
			"C":"T",
			"A":"T",
			"G":"T"
		},
		"A":{
			"U":"N",
			"C":"N",
			"A":"K",
			"G":"K"
		},
		"G":{
			"U":"S",
			"C":"S",
			"A":"R",
			"G":"R"
		}
	},
	"G":{
		"U":{
			"U":"V",
			"C":"V",
			"A":"V",
			"G":"V"
		},
		"C":{
			"U":"A",
			"C":"A",
			"A":"A",
			"G":"A"
		},
		"A":{
			"U":"D",
			"C":"D",
			"A":"E",
			"G":"E"
		},
		"G":{
			"U":"G",
			"C":"G",
			"A":"G",
			"G":"G"
		}
	}
}
def inv_comp(seq):
	out = ""
	for c in seq:
		out = comp[c]+out
	return out
def transcribe(seq):
	return seq.replace("T","U")
def translate(seq):
	return "".join([trans[seq[k]][seq[k+1]][seq[k+2]] for k in range(0,len(seq)-len(seq)%3,3)])
