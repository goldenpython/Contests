################################################################################
#	Cristian Alexandrescu
#	2163013577ba2bc237f22b3f4d006856
#	11a4bb2c77aca6a9927b85f259d9af10db791ce5cf884bb31e7f7a889d4fb385
#	bc9a53289baf23d369484f5343ed5d6c
################################################################################

def Solve():
	Sum = 0;
	for i in range(1, 1000):
		if (i % 3 == 0 or i % 5 == 0):
			Sum += i;
			
	print (Sum);
	


print ("PROJECT EULER 001:");
Solve();


# def ReadParams(ParamsFileName):
	# global ProjectName
	# global BackupDir
	# global SevenZipDir
	# global TempDir
	# global ListDirsToBackup
	
	# file = open(ParamsFileName, "rt")
	# LineIndex = 0
	# for line in file:
		# line = line.strip(" \t\n")
		
		# index = line.find("=")
		# if (index != -1) :
			# list = line.split('=')
			# for i in range(0, len(list)):
				# list[i] = list[i].strip(" \t\n")
				
			#rint list
			
			# if (list[0] == "NAME"):
				# if ((len(list) == 1) or (list[1] == "")):
					# sys.exit("Error at line " + str(LineIndex));
				# ProjectName = GetNicePath(list[1]);
				
			# if (list[0] == "BACKUP_DIR"):
				# if ((len(list) == 1) or (list[1] == "")):
					# sys.exit("Error at line " + str(LineIndex));
				# BackupDir.append(GetNicePath(list[1]));			
				
			# if (list[0] == "7ZIP_DIR"):
				# if ((len(list) == 1) or (list[1] == "")):
					# sys.exit("Error at line " + str(LineIndex));
				# SevenZipDir = GetNicePath(list[1]);	

			# if (list[0] == "DIR2BACKUP"):
				# if ((len(list) == 1) or (list[1] == "")):
					# sys.exit("Error at line " + str(LineIndex));
				# ListDirsToBackup.append(GetNicePath(list[1]))
				
			# if (list[0] == "TEMP_DIR"):
				# if ((len(list) == 1) or (list[1] == "")):
					# sys.exit("Error at line " + str(LineIndex));
				# TempDir = GetNicePath(list[1]);	
				
		# LineIndex = LineIndex + 1

# def GetNicePath(path):
	# index = path.find(' ')
	# list = path.split("\"")
	# ret=""
	
	# for s in list:
		# ret = ret + s
		
	# if (index != -1):
		# ret = "\"" + ret + "\""
		
	# return ret
	
# def PathExists(path):
	# list = path.split("\"")
	# ret=""
	
	# for s in list:
		# ret = ret + s
		
	# return os.path.exists(ret)	
	
	
		

# TimeString = time.strftime("%Y-%m-%d_%Hh-%Mm-%Ss", time.localtime())
# rint TimeString

# if (len(sys.argv) <= 1):
	# sys.exit("No list file specified");
	
# ListFile = sys.argv[1]

# if (PathExists(ListFile) == False):
	# sys.exit("List file does not exists");

# ProjectName = "123"
# BackupDir = []
# SevenZipDir = "123"
# TempDir = "123"
# ListDirsToBackup = []

# ReadParams(ListFile)

# if (PathExists(SevenZipDir) == False):
	# sys.exit("7Zip path is incorect");	

# for dir in ListDirsToBackup:
	# print (GetNicePath(dir))
	# if (PathExists(dir) == False):
		# sys.exit("\nDirectory to backup " + GetNicePath(dir) + " does not exist");	

# print ("Creating temporary directory : " + GetNicePath(TempDir))
# os.system("MKDIR " + GetNicePath(TempDir))

# ProjectArchiveName = ProjectName + "_" + TimeString + ".zip"
# ArchiveFullPath = GetNicePath(TempDir + "\\" + ProjectArchiveName)
# SevenZipExe = GetNicePath(SevenZipDir + "\\7z.exe")

# print (ArchiveFullPath)
# print (SevenZipExe)

# for dir in ListDirsToBackup:
	# CommandLine = "call " + SevenZipExe + " a" + " -tzip " + ArchiveFullPath + " " + GetNicePath(dir)
	# os.system(CommandLine)
	
	
# print
# print
# for dir in BackupDir:
	# if (PathExists(dir) == False):
		# print ("Creating Backup Directory : " + GetNicePath(dir))
		# os.system("MKDIR " + GetNicePath(dir))
		
	# CommandLine = "call COPY " + ArchiveFullPath + " " + GetNicePath(dir)
	# os.system(CommandLine)
	# print
	
# print
# print ("Deleting temp directory : " + GetNicePath(TempDir))
# os.system("call DEL " + GetNicePath(TempDir) + "\\" + ProjectArchiveName + " /q")
# os.system("call RD " + GetNicePath(TempDir))
