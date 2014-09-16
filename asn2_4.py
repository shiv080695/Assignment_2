#!/usr/bin/python3
import csv
import sys, getopt

outputfile=''
mydict={}
z=[]
myupdate={}
mylist=[]
mylist1=[]
mylist2=[]
mylist3=[]
mydict1={}
company=str(input("Enter your company name:"))
shre_cost=float(input("Enter company's share cost:"))
myupdate[company]=shre_cost

def csv_dict_reader(file_obj):
	path="datain.csv"
	reader = csv.DictReader(file_obj,delimiter=',')
	if(reader!={}):
		for line in reader:
			a=(line["Company_name"])
			b=(line["Share_cost"])
			c=(line["status"])
			d=float(b)
			if a==company:
				if shre_cost<d:
					z=[a,shre_cost,'down']
					print(z)
				elif shre_cost>d:
					z=[a,shre_cost,'up']
					print(z)
				else:
					z=[a,d,'none']
					print(z)
		print("Also See in csv fil")
	
		mydict1=line.values()
		file_obj.seek(0,0)
		csv_wrtr(reader,path,z)
	else:
		print("file not opened properly")
def csv_wrtr(reader,path,z):
	with open(path,'w') as f_out:
		f_out.seek(0,0)
		#print(z)
		i=0
		w=z[0]
		#print(w)
		writer = csv.writer(f_out, delimiter=',')
		writer.writerow(["Company_name","Share_cost","status"])
		data=["Apple,123.45,none".split(","),"Google,123,none".split(",")]
		for line in data:
			#print(line[0])
			if line[0]==w:
				line[1]=float(line[1])
				if z[1]<line[1]:
					line[1]=z[1]
					line[2]='down'
				if z[1]>line[1]:
					line[1]=z[1]
					line[2]='up'
		for line in data:
			writer.writerow(line)




def main(argv):
   global outputfile
   try:
      opts, args = getopt.getopt(argv,"f:",["ofile="])
   except getopt.GetoptError:
      print ('test.py -f <inputfile> ')
      sys.exit(1)
   for opt, arg in opts:
      if opt in ("-f", "--ofile"):
         outputfile = arg
      else:
      	print ('test.py -f <inputfile>')

if __name__ == "__main__":
	main(sys.argv[1:])
	with open(outputfile) as f_obj:           
		csv_dict_reader(f_obj)

