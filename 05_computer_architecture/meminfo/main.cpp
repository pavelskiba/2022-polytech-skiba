 #include <iostream> 
#include <fstream> 
#include <string> 

int check_memory() 
{                          
    std::ifstream sysData("/proc/meminfo");   
    if (!sysData.is_open())                   
        return -1;
    else 
{                                    
        std::string temp;                     
        int MemTotal, MemFree;               
        while (!sysData.eof()) 
{              
            sysData >> temp;                  
            if (temp == "MemTotal:")          
                sysData >> MemTotal;         

            if (temp == "MemFree:") 
{         
                sysData >> MemFree;
                break;                        
            }
        }
        return 100 - MemFree / (MemTotal / 100); 
    }
}

void out(int percent) { 
    int i = 0;                          
    for (i; i < percent / 10; i++) 
{    
        std::cout << "|";               
    }
    for (i; i < 10; i++) 
{              
        std::cout << ".";              
    }
    std::cout << " " << percent << std::endl;   
}

int main() //main
{
    out(check_memory()); 
    return 0; 
}