#include "./headers/exceptions.h"



void raise_exception(int except, char *file, int line){
        if(except == AllocationError){
                print("AllocationError: %s %d", file, line);
                exit(AllocationError);
        }
        else if(except == ReallocationError){
                print("ReallocationError %s %d", file, line);
                exit(ReallocationError);
        }
        else if(except == MemoryError){
                print("MemoryError %s %d", file, line);
                exit(MemoryError);
        }
        else if(except == FileOpenError){
                print("FileOpenError %s %d", file, line);
                exit(FileOpenError);
        }

}