#include "snowman.hpp"


namespace ariel{
    std::string snowman(int dna){
        const int MIN =11111111;
        const int MAX =44444444;
        const int GOOD =1;
        const int BAD =0;
        const int length =8;
        const int DIVIDER=10;
        const int HAT=0;
        const int NOSE_OR_MOUTH=1;
        const int LEFT_EYE=2;
        const int RIGHT_EYE=3;
        const int LEFT_HAND=4;
        const int RIGHT_HAND=5;
        const int BELLY=6;
        const int BOTTOM=7;
        const std::array<std::array<std::string,4>,2>Hat={{{"     "," ___ ","  _  "," ___ "},
                                                    {"_===_","....."," /_\\ ","(_*_)"}}};
        const std::array<std::string,4>Nose_or_Mouth={",",".","_"," "};
        const std::array<std::string,4>Eye={".","o","O","-"};
        const std::array<std::array<std::string,4>,2>Left_Hand={{{" ","\\"," "," "},
                                                   {"<"," ","/"," "}}};
        const std::array<std::array<std::string,4>,2>Right_Hand={{{" ","/"," "," "},
                                                    {">"," ","\\"," "}}};
        const std::array<std::string,4>Torso={" : ","] [","> <","   "};
        const std::array<std::string,4>Bottom={" : ","\" \"","___","   "};
        std::string ans;
        std::array<int,length> arr={};
        int case_ = GOOD; //case

        if (dna<MIN || dna>MAX){
            case_=BAD;
        }
        int temp=0;
        int dev = 1;
        int i=length-1;
        int temp_dna = dna;

        for(int j=length; j>0; j--){
            temp = temp_dna%DIVIDER;
            temp_dna=temp_dna/DIVIDER;
            /*
            in case one of the number digits isnt good:
            */
            if(temp<1 || temp>4){
                case_=BAD;
                break;
            }
            arr.at(j-1)=(temp-1);
        }

        ans =" "+Hat[0][arr.at(HAT)]+" \n"
                            +" "+Hat[1][arr.at(HAT)]+" \n"
                            +Left_Hand[0][arr.at(LEFT_HAND)]+"("+Eye.at(arr.at(LEFT_EYE))+Nose_or_Mouth.at(arr.at(NOSE_OR_MOUTH))+Eye.at(arr.at(RIGHT_EYE))+")"+Right_Hand[0][arr.at(RIGHT_HAND)]+"\n"
                            +Left_Hand[1][arr.at(LEFT_HAND)]+"("+Torso.at(arr.at(BELLY))+")"+Right_Hand[1][arr.at(RIGHT_HAND)]+"\n"
                            +" ("+Bottom.at(arr.at(BOTTOM))+") \n";                     

        if(case_ == GOOD){
            return ans;
        }
        else{
            throw std::invalid_argument{"Invalid code '"+std::to_string(dna)+"'"};
        }
    }
}
