// https://leetcode.com/problems/integer-to-roman

class Solution {
public:
    string intToRoman(int num) {
        map<int,char>m;
        m.insert({1,'I'});
        m.insert({5,'V'});
        m.insert({10,'X'});
        m.insert({50,'L'});
        m.insert({100,'C'});
        m.insert({500,'D'});
        m.insert({1000,'M'});
        int i=0,c=0;
        string t="";
        while(num>0){
            if(num>=500 && num<1000){
                if(num>=900){
                    t=t+m[100]+m[1000];
                    num=num-900;
                }
                else{
                    if(num==1000){
                        t=t+m[1000];
                        num=num-1000;
                    }
                    else{
                        t=t+m[500];
                        num=num-500;
                    }
                }
            }
            else if(num>=100 && num<500){
                if(num>=400){
                    t=t+m[100]+m[500];
                    num=num-400;
                }
                else{
                    if(num==500){
                        t=t+m[500];
                        num=num-500;
                    }
                    else{
                    t=t+m[100];
                    num=num-100;
                    }
                }
            }
            else if(num>=50 && num<100){
                if(num>=90){
                    t=t+m[10]+m[100];
                    num=num-90;
                }
                else{
                    if(num==100){
                        t=t+m[100];
                        num=num-100;
                    }
                    else{
                    t=t+m[50];
                    num=num-50;
                    }
                }
            }
            else if(num>=10 && num<50){
                if(num>=40){
                    t=t+m[10]+m[50];
                    num=num-40;
                }
                else{
                    if(num==50){
                        t=t+m[50];
                        num=num-50;
                    }
                    else{
                    t=t+m[10];
                    num=num-10;
                    }
                }
            }
            else if(num>=5 && num<10){
                if(num==9){
                    t=t+m[1]+m[10];
                    num=num-9;
                }
                else{
                    t=t+m[5];
                    num=num-m[5];
                }
            }
            else if(num>=1 && num<5){
                if(num==4){
                    t=t+m[1]+m[5];
                    num=num-4;
                }
                else{
                    t=t+m[1];
                    num=num-1;
                }
            }
        }
        return t;
    }
};