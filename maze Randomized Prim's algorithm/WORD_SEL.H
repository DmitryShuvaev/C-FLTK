#ifndef WORD_SEL_H
#define WORD_SEL_H
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <vector>
#include <time.h>

using namespace std;
class Word_sel
{
    public:

        Word_sel();
 void init();
 void loadWords();

        struct Word{
    int x,y,size,num;
    string word;
     bool horizontalw,verticalw;
	 Word(){horizontalw=false;verticalw=false;num=0;}
};
struct LetterChar{
    char c;
    bool start_pos;//default fals
	bool end_of_word;
	int num;
    bool horizontal,vertical,horNext,vertNext;
};
    struct Maxw{
            string maxword;
            vector<string>TempW;
            int maxind;
			int x,y;
            Maxw(){maxind=0;maxword="",x=0;y=0;}
            };
vector <Word>words;
vector<string>TempW;
//vector<string
//vector<string>LWord;
vector<Word>horWords;
vector<Word>verWords;
vector<vector<LetterChar> >crossw;
//
int wordcounter;
//
int getRandom(int from, int to){
	int dif = (to+1) - from;
	return from + rand() % dif;
}
void printcrosw();
virtual ~Word_sel();
void clearCros();
//grid
void setGrid(const Word &w){
int startx=w.x;
if(w.horizontalw){
	for(int y=w.y+1;y<crossw.size();y++){
		for(int x=w.x;x<startx+w.size;x++){
		if((x%2!=0 ||y%2!=0) && !(isalpha(crossw[y][x].c))){
			crossw[y][x].c='#';
		}
		}
	}
}
}
//
void swapw(const string w1,const string w2){
    int indexw1=0,indexw2=0;
for(int i=0;i<TempW.size();i++){
    if(TempW[i]==w1){
       indexw1=i;
    }
    else if(TempW[i]==w2){
       indexw2=i;
    }
}
TempW[indexw1]=w2;
TempW[indexw2]=w1;
//for(int i=0;i<TempW.size();i++){
//    cout<<TempW[i]<<'\n';
//}
}//


//
string findword(int sx,int sy){
string s="";
vector<Maxw>mword;

	//if (!LWord.empty())
 //   LWord.clear();
int startx=sx;
int starty=sy;
int size=TempW.size();
//replaceWords(sx,sy);
for(int i=0;i<size;i++){
        startx=sx; starty=sy;
		s="";
	if(TempW[i][0]==crossw[starty][startx].c){
		for(int x=0;x<TempW[i].size();x++){
			//if(crossw[sy][sx].horNext)
			if(crossw[sy][sx].horizontal&&crossw[sy][sx].vertical==false){
				if(TempW[i][x]!=crossw[starty][startx].c && crossw[starty][startx].c!='8' && crossw[starty][startx].c!='#'&&crossw[starty][startx].c!=' '|| TempW[i].size()+sy>crossw.size())break;
				else s+=TempW[i][x];
               starty++;
			   if(s.size()>crossw.size())break;
			}else if(crossw[sy][sx].vertical&& crossw[sy][sx].horizontal==false){
				if(TempW[i][x]!=crossw[starty][startx].c && crossw[starty][startx].c!='8' &&crossw[starty][startx].c!=' '&& crossw[starty][startx].c!='#'|| TempW[i].size()+sx>crossw[starty].size())break;
				else s+=TempW[i][x];
				startx++;
				if(s.size()>crossw[starty].size())break;
			}

		}//end for loop
		
		if(s.size()==TempW[i].size()){
					s=TempW[i];
					Maxw mw;
					mw.maxword=s;
					mw.x=i;
					mword.push_back(mw);
		           // TempW[i]=" ";//so cant' use it again
			//return s;
		}
		//else {startx=sx; starty=sy;}


	}
}
            //cout<<'\n';
            //for(int i=0;i<mword.size();i++)cout<<"lword["<<i<<"]="<<mword[i].maxword<<' ';
            //cout<<'\n';
			if(mword.size()>1){
			int hw=getRandom(0,mword.size()-1);
			//cout<<hw;
			TempW[mword[hw].x]=" ";
			return mword[hw].maxword;
			}else if(mword.size()>0){
				TempW[mword[0].x]=" ";
				return mword[0].maxword;
			}
return  "";
}
void insertword(Word w){
int startx=w.x;
int starty=w.y;
//if( crossw[starty][startx].horNext==true) crossw[starty][startx].horNext=false;

if(w.horizontalw==true && w.verticalw==false){
       
    for(int i=0;i<w.size;i++){
	if(i==0){
		if(crossw[starty][startx].num==0)
		crossw[starty][startx].num=++wordcounter;;
	}   
	    
        crossw[starty][startx].c=w.word[i];
		 crossw[starty][startx].horizontal=true;//puting horizontal word
		 if(startx%2!=0)crossw[starty][startx].vertical=true;
		 	if(i>0&&i==w.size-1){crossw[starty][startx].horNext=true;
		    //crossw[starty][startx+1].c='v';
            }
        startx++;

	}
	//
	w.num=wordcounter;	
	if(w.word!="")
	horWords.push_back(w);
}else if(w.horizontalw==false && w.verticalw==true){
        //crossw[starty][startx].start_pos=true;
    for(int i=0;i<w.size;i++){
		if(i==0){
			if(crossw[starty][startx].num==0)
			crossw[starty][startx].num=++wordcounter;;
		}
        crossw[starty][startx].c=w.word[i];
		 crossw[starty][startx].vertical=true;//puting vertical word
		 if(starty%2!=0)crossw[starty][startx].horizontal=true;
		 if(i>0&&i==w.size-1){crossw[starty][startx].vertNext=true;
		 //crossw[starty+1][startx].c='z';
		 }
        starty++;

    }
		w.num=wordcounter;	
	if(w.word!="")
	verWords.push_back(w);
}

}
string findwordHorNext(int sx,int sy){
string s="";
vector<Maxw>mword;
if( crossw[sy][sx].horNext==true) crossw[sy][sx].horNext=false;
	//if (!LWord.empty())
 //   LWord.clear();
int startx=sx;
int starty=sy;
int size=TempW.size();
//replaceWords(sx,sy);
for(int i=0;i<size;i++){
        startx=sx; starty=sy;
		s="";
	if(TempW[i][0]==crossw[starty][startx].c){
		for(int x=0;x<TempW[i].size();x++){
			//if(crossw[sy][sx].horNext)
			if(crossw[sy][sx].horizontal&&crossw[sy][sx].vertical==false){
				if(TempW[i][x]!=crossw[starty][startx].c && crossw[starty][startx].c!='8' && crossw[starty][startx].c!='#'&&crossw[starty][startx].c!=' '|| TempW[i].size()+sx>crossw[sy].size())break;
				else s+=TempW[i][x];
               startx++;
			  // if(s.size()>crossw[starty].size())break;
			}

		}//end for loop
		
		if(s.size()==TempW[i].size()){
					s=TempW[i];
					Maxw mw;
					mw.maxword=s;
					mw.x=i;
					mword.push_back(mw);
		           // TempW[i]=" ";//so cant' use it again
			//return s;
		}
		//else {startx=sx; starty=sy;}


	}
}
            cout<<'\n';
            for(int i=0;i<mword.size();i++)cout<<"lwordhornext["<<i<<"]="<<mword[i].maxword<<' ';
            cout<<'\n';
			if(mword.size()>1){
			int hw=getRandom(0,mword.size()-1);
			cout<<hw;
			TempW[mword[hw].x]=" ";
			return mword[hw].maxword;
			}else if(mword.size()>0){
				TempW[mword[0].x]=" ";
				return mword[0].maxword;
			}
return  "";
}
string findwordHorhorver(int sx,int sy){
string s="";
vector<Maxw>mword;

	//if (!LWord.empty())
 //   LWord.clear();
int startx=sx;
int starty=sy;
int size=TempW.size();
//replaceWords(sx,sy);
for(int i=0;i<size;i++){
        startx=sx; starty=sy;
		s="";
	if(TempW[i][0]==crossw[starty][startx].c){
		for(int x=0;x<TempW[i].size();x++){
			//if(crossw[sy][sx].horNext)
			
				if(TempW[i][x]!=crossw[starty][startx].c && crossw[starty][startx].c!='8' && crossw[starty][startx].c!='#'&&crossw[starty][startx].c!=' '|| TempW[i].size()+sx>crossw[sy].size())break;
				else s+=TempW[i][x];
               startx++;
			

		}//end for loop
		
		if(s.size()==TempW[i].size()){
					s=TempW[i];
					Maxw mw;
					mw.maxword=s;
					mw.x=i;
					mword.push_back(mw);
		           // TempW[i]=" ";//so cant' use it again
			//return s;
		}
		//else {startx=sx; starty=sy;}


	}
}
            cout<<'\n';
            for(int i=0;i<mword.size();i++)cout<<"lwordhornext["<<i<<"]="<<mword[i].maxword<<' ';
            cout<<'\n';
			if(mword.size()>1){
			int hw=getRandom(0,mword.size()-1);
			cout<<hw;
			TempW[mword[hw].x]=" ";
			return mword[hw].maxword;
			}else if(mword.size()>0){
				TempW[mword[0].x]=" ";
				return mword[0].maxword;
			}
return  "";
}
//
string findwordVerthorver(int sx,int sy){
string s="";
vector<Maxw>mword;

	//if (!LWord.empty())
 //   LWord.clear();
int startx=sx;
int starty=sy;
int size=TempW.size();
for(int i=0;i<size;i++){
        startx=sx; starty=sy;
		s="";
	if(TempW[i][0]==crossw[starty][startx].c){
		for(int x=0;x<TempW[i].size();x++){
			//if(crossw[sy][sx].horNext)
			
				if(TempW[i][x]!=crossw[starty][startx].c && crossw[starty][startx].c!='8' && crossw[starty][startx].c!='#'&&crossw[starty][startx].c!=' '|| TempW[i].size()+sy>crossw.size())break;
				else s+=TempW[i][x];
               starty++;
			

		}//end for loop
		
		if(s.size()==TempW[i].size()){
					s=TempW[i];
					Maxw mw;
					mw.maxword=s;
					mw.x=i;
					mword.push_back(mw);
		           // TempW[i]=" ";//so cant' use it again
			//return s;
		}
		//else {startx=sx; starty=sy;}


	}
}
            cout<<'\n';
            for(int i=0;i<mword.size();i++)cout<<"lwordhornext["<<i<<"]="<<mword[i].maxword<<' ';
            cout<<'\n';
			if(mword.size()>1){
			int hw=getRandom(0,mword.size()-1);
			cout<<hw;
			TempW[mword[hw].x]=" ";
			return mword[hw].maxword;
			}else if(mword.size()>0){
				TempW[mword[0].x]=" ";
				return mword[0].maxword;
			}
return  "";
}
//
string findwordVertnext(int sx,int sy){
string s="";
vector<Maxw>mword;
if( crossw[sy][sx].vertNext==true) crossw[sy][sx].vertNext=false;
	//if (!LWord.empty())
 //   LWord.clear();
int startx=sx;
int starty=sy;
int size=TempW.size();
//replaceWords(sx,sy);
for(int i=0;i<size;i++){
        startx=sx; starty=sy;
		s="";
	if(TempW[i][0]==crossw[starty][startx].c){
		for(int x=0;x<TempW[i].size();x++){
            if(crossw[sy][sx].vertical&& crossw[sy][sx].horizontal==false){
				if(TempW[i][x]!=crossw[starty][startx].c && crossw[starty][startx].c!='8' &&crossw[starty][startx].c!=' '&& crossw[starty][startx].c!='#'|| TempW[i].size()+sy>crossw.size())break;
				else s+=TempW[i][x];
				starty++;
			}

		}//end for loop
		
		if(s.size()==TempW[i].size()){
					s=TempW[i];
					Maxw mw;
					mw.maxword=s;
					mw.x=i;
					mword.push_back(mw);
		           // TempW[i]=" ";//so cant' use it again
			//return s;
		}
		//else {startx=sx; starty=sy;}


	}
}
            cout<<'\n';
            for(int i=0;i<mword.size();i++)cout<<"lword["<<i<<"]="<<mword[i].maxword<<' ';
            cout<<'\n';
			if(mword.size()>1){
			int hw=getRandom(0,mword.size()-1);
			cout<<hw;
			TempW[mword[hw].x]=" ";
			return mword[hw].maxword;
			}else if(mword.size()>0){
				TempW[mword[0].x]=" ";
				return mword[0].maxword;
			}
return  "";
}
void checkLetters(){
	for(int y=0;y<crossw.size();y++){
		for(int x=0;x<crossw[y].size();x++){
           if(crossw[y][x].c=='8'){
   //         Word w;
			//w.x=x;w.y=y;
			//w.word=TempW[0];
			//TempW[0]=" ";
			//w.size=w.word.size();
			//w.horizontalw=true; 
			//if(w.word!=" ")
			//insertword(w);
			//setGrid(w);
			//return;

		   }
		   else if(isalpha(crossw[y][x].c)){
			   if(crossw[y][x].horNext){
			Word w;
			w.x=x;w.y=y;
			w.word=findwordHorNext(x,y);
			w.size=w.word.size();
			
			w.horizontalw=true;
			if(w.word!=" "){
			//if(crossw[y][x].num==0)
			//w.num=++wordcounter;
			insertword(w);
			}
			setGrid(w);
			//return;
			   }
			   if(crossw[y][x].vertNext){
			Word w;
			w.x=x;w.y=y;
			w.word=findwordVertnext(x,y);
			w.size=w.word.size();
			
			w.verticalw=true;
			if(w.word!=" "){
			//if(crossw[y][x].num==0)
			//w.num=++wordcounter;
			insertword(w);
			}
			//setGrid(w);
			//return;
			   }
			if(crossw[y][x].horizontal&&!crossw[y][x].vertical){
			Word w;
			w.x=x;w.y=y;
			w.word=findword(x,y);
			//cout<<"w.word="<<w.word<<'\n';
			//LWord.clear();
			w.size=w.word.size();
			
			w.verticalw=true;
			if(w.word!=" "){
			//if(crossw[y][x].num==0)
			//w.num=++wordcounter;
			insertword(w);
			}
			//setGrid(w);
			//return;
			}
			else if(crossw[y][x].vertical&& !crossw[y][x].horizontal){
			Word w;
			w.x=x;w.y=y;
			w.word=findword(x,y);
			//cout<<"w.word="<<w.word<<'\n';
			//LWord.clear();
			w.size=w.word.size();
			
			w.horizontalw=true;
			if(w.word!=" "){
			//if(crossw[y][x].num==0)
           //w.num=++wordcounter;
			insertword(w);
			}
			setGrid(w);
			//cout<<"w.word="<<w.word;
			}
			else if(crossw[y][x].vertical && crossw[y][x].horizontal)
			//hor and verti words inserted but in the end of word can be lent to insert another word
			{
			Word w;
			if(crossw[y][x].horNext==true){
			w.x=x;w.y=y;
			w.word=findwordHorhorver(x,y);
			if(w.word!=""){crossw[y][x].horNext=true;//crossw[y][x].c='w';
			w.size=w.word.size();
			
			w.horizontalw=true;
			if(w.word!=" "){
				//if(crossw[y][x].num==0)
				//w.num=++wordcounter;
			    insertword(w);
			}
			setGrid(w);
			crossw[y][x].horNext=false;
			//if(y>0)
			//y--;
			}else
			{
			//w.x=x;w.y=y;
			//w.word=findwordVerthorver(x,y);
			//w.size=w.word.size();
			//w.verticalw=true;
			//if(w.word!=""){
			//	crossw[y][x].vertNext=true;
			//	insertword(w);
			//	crossw[y][x].vertNext=false;
			//	cout<<"vertw.word="<<w.word;
			//}
			}
			}if(crossw[y][x].vertNext==true){
						w.x=x;w.y=y;
			w.word=findwordVerthorver(x,y);
			w.size=w.word.size();
			
			w.verticalw=true;
			w.horizontalw=false;
			if(w.word!=""){
				crossw[y][x].vertNext=true;
				//if(crossw[y][x].num==0)
				//w.num=++wordcounter;
				insertword(w);
				crossw[y][x].vertNext=false;
				cout<<"vertw.word="<<w.word;
			}//
			}
			}
		   }
		}
	}
//cout<<crossw[2][2].vertical;
}
    protected:

    private:
};

#endif // WORD_SEL_H
