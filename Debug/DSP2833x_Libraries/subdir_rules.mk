################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
DSP2833x_Libraries/%.obj: ../DSP2833x_Libraries/%.asm $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"D:/1study/app/CCS/CCS12/ccs/tools/compiler/ti-cgt-c2000_22.6.1.LTS/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --include_path="D:/1study/source/CCS/workspace12/_28335_DEFAULT/_28335_DEFAULT/User_include" --include_path="D:/1study/app/CCS/CCS12/ccs/tools/compiler/ti-cgt-c2000_22.6.1.LTS/include" --include_path="D:/1study/source/CCS/workspace12/_28335_DEFAULT/_28335_DEFAULT/header_include" --include_path="D:/1study/source/CCS/workspace12/_28335_DEFAULT/_28335_DEFAULT/common_include" -g --diag_warning=225 --display_error_number --diag_wrap=off --preproc_with_compile --preproc_dependency="DSP2833x_Libraries/$(basename $(<F)).d_raw" --obj_directory="DSP2833x_Libraries" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

DSP2833x_Libraries/%.obj: ../DSP2833x_Libraries/%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"D:/1study/app/CCS/CCS12/ccs/tools/compiler/ti-cgt-c2000_22.6.1.LTS/bin/cl2000" -v28 -ml -mt --float_support=fpu32 --include_path="D:/1study/source/CCS/workspace12/_28335_DEFAULT/_28335_DEFAULT/User_include" --include_path="D:/1study/app/CCS/CCS12/ccs/tools/compiler/ti-cgt-c2000_22.6.1.LTS/include" --include_path="D:/1study/source/CCS/workspace12/_28335_DEFAULT/_28335_DEFAULT/header_include" --include_path="D:/1study/source/CCS/workspace12/_28335_DEFAULT/_28335_DEFAULT/common_include" -g --diag_warning=225 --display_error_number --diag_wrap=off --preproc_with_compile --preproc_dependency="DSP2833x_Libraries/$(basename $(<F)).d_raw" --obj_directory="DSP2833x_Libraries" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


