#include "level.h"

Level::Level(){
	loadPalette("sheet.txt");
	
	tw_=4; th_=3;
	pw_=8; ph_=4;
	pal_= (tw_*pw_+1)*th_*ph_;
	
	cout<<"Initializing map... ";
	charList_ = "#.@@? 01!%=U++++/x-7r7rI\\X|LJLJH";
	initMap_();
	cout<<"Success!"<<endl;
	
	
	charLen_ = charList_.length();
	cout<<charList_<<(charLen_ == pw_*ph_)<<endl;
}

void Level::initMap_(){
	
	for (int k = 0; k<charLen_; k+=charLen_){
		for (int j = 0; j<ph_; j++){
			for (int i = 0; i<pw_; i++){
				vector<int> vec={i,j};
				//m_.insert({charList[k], vec});
				m_.insert(pair<char, vector<int>>(charList_[k], vec));
				//m_[charList[k]]=arr;
				//printf("%c(%d, %d): %i, %i\n",charList_[k],i,j,m_[charList_[k]][0],m_[charList_[k]][1]);
				k++;
			};
		};
	};
}

void Level::loadPalette(string fileName){
	fstream file;
	
	file.open(fileName);
	cout<<"Palette opened... ";
	if (file.fail()){
		perror(fileName.c_str());
		system("PAUSE");
		exit(1);
	}
	
	string line;
	
	while (getline(file,line)){paletteData_.push_back(line);}
	
	file.close();
	cout<<"Palette loaded okay!"<<endl;
}

void Level::loadLevel(string fileName){
	levelData_.clear();
	
	fstream file;
	
	file.open(fileName);
	cout<<"Level opened... ";
	if (file.fail()){
		perror(fileName.c_str());
		system("PAUSE");
		exit(1);
	}
	
	string line;
	int maxim = 0;
	int i=0;

	while (getline(file,line)){
		levelData_.push_back(line);
		int comp = line.size();
		if (comp > maxim){maxim=comp;}
		i++;
	}
	magic_ = (i * th_) * ((maxim+1) * tw_); //lines * wide enough to get the line width of a file * tile 3 * 4
	file.close();
	cout<<"Level loaded okay!"<<endl;
}


void Level::print(){
	char buf[magic_];
	char* const last = buf + sizeof(buf);
	char* out = buf;
	
	//for (unsigned int i =0;i<levelMap_.size();i++){
	for (unsigned int i =0; i<levelData_.size(); i++){
		//for (unsigned int j =0;j<levelMap_[i].size();j++){
		for (unsigned int k = 0; k < th_; k++){
			//out+=snprintf(out, last - out, "%c", char(levelMap_[i][j]));
			for (unsigned int j =0;j<levelData_[i].size();j++){
				out+=snprintf(out, last - out, tileGrab(levelData_[i][j])[k].c_str());
				//cout<<"deliberate..."<<endl;
			} //tileGrab must return an array of 3 strings with length 4+1 (null termimnator)
			out+=snprintf(out, last - out, "\n");
		}
		
	}
	*out = '\0';
	printf("%s", buf);
}

char Level::getChar(int x, int y){return levelData_[y][x];}

void Level::setChar(int x, int y, char ch){levelData_[y][x]=ch;}

vector<string> Level::tileGrab(char ch){
	if (charList_.find(ch)!=string::npos){
		int x=m_[ch][0], y=m_[ch][1];
		string string1 = paletteData_[y*th_].substr(x*tw_, tw_);
		//(paletteData_[y*th_][x*tw_],paletteData_[y*th_][x*tw_+3]);
		string string2 = paletteData_[y*th_+1].substr(x*tw_, tw_);
		//(paletteData_[y*th_+1][x*tw_],paletteData_[y*th_+1][x*tw_+3]);
		string string3 = paletteData_[y*th_+2].substr(x*tw_, tw_);
		//(paletteData_[y*th_+2][x*tw_],paletteData_[y*th_+2][x*tw_+3]);
		
		return {string1, string2, string3};
	}
	else return {"####","#??#","####"};
}