#include "Word_sel.h"

Word_sel::Word_sel()
{
    //ctor
    init();
}

Word_sel::~Word_sel()
{
    //dtor
}
void Word_sel::init(){
    LetterChar l;
    l.c='8';l.num=0;l.end_of_word=false;
    l.start_pos=false;l.horizontal=false;l.vertical=false;// l.horNext=false; l.vertNext=false;
    for (int i = 0; i < 8; i++) {
        crossw.push_back(vector<LetterChar>()); // Add an empty row
    }
            for (int y = 0; y < crossw.size(); y++) {
            for (int x = 0; x < 8; x++)
            crossw[y].push_back(l); // Add column to all rows
        }
//TempW.push_back("dog");
//TempW.push_back("did");
//TempW.push_back("daf");
//TempW.push_back("def");
//TempW.push_back("dom");
//TempW.push_back("god");
//TempW.push_back("gaf");
//TempW.push_back("mug");
//TempW.push_back("mud");
//TempW.push_back("muf");
//TempW.push_back("mod");
//TempW.push_back("mom");
//TempW.push_back("fed");
//TempW.push_back("fuf");
//TempW.push_back("fef");
//TempW.push_back("dad");
//TempW.push_back("fom");
//TempW.push_back("fam");
//TempW.push_back("domuf");
//
			wordcounter=0;
			loadWords();
            Word w;
			w.x=0;w.y=0;
			int frw=getRandom(0,TempW.size()-1);
			while(TempW[frw].size()>crossw[0].size())
                 frw=getRandom(0,TempW.size()-1);
			
				w.word=TempW[frw];
				cout<<"0word ="<<w.word<<endl;
				
				TempW[frw]=" ";
				w.size=w.word.size();

				//cout<<"w.num="<<w.num<<endl;
				w.horizontalw=true; 
				if(w.word!=" "){
				//w.num=++wordcounter;
				insertword(w);
				setGrid(w);
				}

}//
void Word_sel::loadWords(){
  string line;
  //vector<string>lines;
  ifstream myfile ("eng_words.txt");
  if (myfile.is_open())
  {
    while ( myfile.good() )
    {
      getline (myfile,line);
      //cout << line << endl;
	  TempW.push_back(line);
    }
    myfile.close();
  }
  else cout << "Unable to open file"; 
  //for(int i=0;i<lines.size();i++)
	 // cout<<lines[i]<<endl;

}
void Word_sel::printcrosw(){
    cout<<"print cros\n";
        for (int y = 0; y < crossw.size(); y++) {
        for (int x = 0; x < crossw[y].size(); x++)
        cout<<crossw[y][x].c<<' ';
        cout<<'\n';
    }
    cout<<"print cros end\n";
	    for (int y = 0; y < crossw.size(); y++) {
        for (int x = 0; x < crossw[y].size(); x++)
        cout<<crossw[y][x].num<<' ';
        cout<<'\n';
    }
}
