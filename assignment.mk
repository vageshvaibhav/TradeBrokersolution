##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=assignment
ConfigurationName      :=Debug
WorkspacePath          := "C:\Users\vagesh\Desktop\CITI_assignment\citi"
ProjectPath            := "C:\Users\vagesh\Desktop\CITI_assignment\citi\assignment"
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=vagesh
Date                   :=18/10/2015
CodeLitePath           :="C:\Program Files (x86)\CodeLite"
LinkerName             :=C:/MinGW-4.7.1/bin/g++.exe
SharedObjectLinkerName :=C:/MinGW-4.7.1/bin/g++.exe -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="assignment.txt"
PCHCompileFlags        :=
MakeDirCommand         :=makedir
RcCmpOptions           := 
RcCompilerName         :=C:/MinGW-4.7.1/bin/windres.exe
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := C:/MinGW-4.7.1/bin/ar.exe rcu
CXX      := C:/MinGW-4.7.1/bin/g++.exe
CC       := C:/MinGW-4.7.1/bin/gcc.exe
CXXFLAGS :=  -g -O0 -std=c++11 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := C:/MinGW-4.7.1/bin/as.exe


##
## User defined environment variables
##
CodeLiteDir:=C:\Program Files (x86)\CodeLite
UNIT_TEST_PP_SRC_DIR:=C:\UnitTest++-1.3
Objects0=$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IntermediateDirectory)/UserInterface.cpp$(ObjectSuffix) $(IntermediateDirectory)/Strategy.cpp$(ObjectSuffix) $(IntermediateDirectory)/Broker.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@$(MakeDirCommand) "./Debug"


$(IntermediateDirectory)/.d:
	@$(MakeDirCommand) "./Debug"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/main.cpp$(ObjectSuffix): main.cpp $(IntermediateDirectory)/main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/vagesh/Desktop/CITI_assignment/citi/assignment/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/main.cpp$(DependSuffix) -MM "main.cpp"

$(IntermediateDirectory)/main.cpp$(PreprocessSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.cpp$(PreprocessSuffix) "main.cpp"

$(IntermediateDirectory)/UserInterface.cpp$(ObjectSuffix): UserInterface.cpp $(IntermediateDirectory)/UserInterface.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/vagesh/Desktop/CITI_assignment/citi/assignment/UserInterface.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/UserInterface.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/UserInterface.cpp$(DependSuffix): UserInterface.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/UserInterface.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/UserInterface.cpp$(DependSuffix) -MM "UserInterface.cpp"

$(IntermediateDirectory)/UserInterface.cpp$(PreprocessSuffix): UserInterface.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/UserInterface.cpp$(PreprocessSuffix) "UserInterface.cpp"

$(IntermediateDirectory)/Strategy.cpp$(ObjectSuffix): Strategy.cpp $(IntermediateDirectory)/Strategy.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/vagesh/Desktop/CITI_assignment/citi/assignment/Strategy.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Strategy.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Strategy.cpp$(DependSuffix): Strategy.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Strategy.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Strategy.cpp$(DependSuffix) -MM "Strategy.cpp"

$(IntermediateDirectory)/Strategy.cpp$(PreprocessSuffix): Strategy.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Strategy.cpp$(PreprocessSuffix) "Strategy.cpp"

$(IntermediateDirectory)/Broker.cpp$(ObjectSuffix): Broker.cpp $(IntermediateDirectory)/Broker.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/vagesh/Desktop/CITI_assignment/citi/assignment/Broker.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Broker.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Broker.cpp$(DependSuffix): Broker.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Broker.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Broker.cpp$(DependSuffix) -MM "Broker.cpp"

$(IntermediateDirectory)/Broker.cpp$(PreprocessSuffix): Broker.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Broker.cpp$(PreprocessSuffix) "Broker.cpp"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


