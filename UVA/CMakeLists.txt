cmake_minimum_required (VERSION 2.6)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)


function(CreateProject Sources ProjectName SolutionPath Result)
	project (${ProjectName})

	add_executable(
		${ProjectName}
		${Sources}
	)

	set_target_properties(${ProjectName} PROPERTIES FOLDER ${SolutionPath})
	if (CMAKE_COMPILER_IS_GNUCXX)
		target_link_libraries(${ProjectName} crypt m)
	endif()

	if (OPT_DEFINE_ONLINE_JUDGE)
		set(ProjectDefines -DONLINE_JUDGE)
	endif(OPT_DEFINE_ONLINE_JUDGE)

	if (MSVC)
		set(ProjectDefines "${ProjectDefines} -D_CRT_SECURE_NO_WARNINGS")
	endif()
	if (CMAKE_COMPILER_IS_GNUCXX)
		set(CompilerOptions "${CompilerOptions} -std=c++0x -O2 -pipe -Wno-deprecated -Wno-deprecated-declarations -Wno-unused-result")
	endif()
	set_target_properties(${ProjectName} PROPERTIES COMPILE_FLAGS ${ProjectDefines}${CompilerOptions})

endfunction()

function(ProcessFolder Folder SolutionPath Result)
	file(GLOB files "${Folder}/*.c*")
	foreach(file ${files})
		get_filename_component(fileName ${file} NAME)
		get_filename_component(fileNameWithoutExtension ${file} NAME_WE)
		CreateProject("${file}" "${fileNameWithoutExtension}" "${SolutionPath}" Result)
	endforeach()
endfunction()


option(OPT_DEFINE_ONLINE_JUDGE "Define DONLINE_JUDGE" OFF)

ProcessFolder("${CMAKE_SOURCE_DIR}" "Projects" Result)



project (UVA)
