
/***************************************************************************************
[[[[[[[[[[[													        ]]]]]]]]]]]]]]]]]]]]
[[[[[[[[[[[		Data Structure and Algorithm Group Assignment I.	]]]]]]]]]]]]]]]]]]]]
[[[[[[[[[[[					Group 1	- Singly linked list			]]]]]]]]]]]]]]]]]]]]
[[[[[[[[[[[				Music List Management System(MLMS)	        ]]]]]]]]]]]]]]]]]]]]
[[[[[[[[[[[														    ]]]]]]]]]]]]]]]]]]]]
****************************************************************************************
Group Members			  	ID:

Mastewal 	Yaregal		1306819
Feven 		Abebe		1307292
Bereket		Mekit		1306531
Haile 		Amare		1306110
Abenezer 	Birhanu		1306674
*/

#include<iostream>
#include<string.h>
#include<string>
#include<cstring>
#include<cstdlib>
#include<conio.h>
#include<sstream>
using namespace std;

/*
##################################################
------------Structure Declaration-----------------
##################################################
*/
struct music{
    char musicID[20];
    char title[40];
    char artist[30];
    char genre[40];
    int yearReleased;
    float duration;
    music *next;
};
music *start=NULL;//The starting point for for the linked list

//-------------------------------------------------------------------------------------------

/*we created the following non-linked list Structure to create a function generated linked list later on.
The reason we included this is incase the user wants sample music data instead of inserting by himself.
*/

struct musicsample{
    char musicID[20];
    char title[40];
    char artist[30];
    char genre[40];
    int yearReleased;
    float duration;
};
/*
################################################################
------------Declaration of all the functions used---------------
################################################################
*/

//------------------///major functions Directly Related with questions ///--------------------//
//Question 1
void insertAtBeginning();
//Question 2
void insertAtEnd();
//question 3
void insertAtMiddle();
//question 4
void deleteFirst();
//question 5
void deleteLast();
//question 6
void deleteNodeAttrib();
//question 7
void deleteNthNode();
//question 8
void searchMin();
//question 9
void searchMax();
//question 10
void average();
//question 11
void deleteMin();
//question 12
void deleteMax();
//question 13
void searchByAttrib();
//question 14
void displayAll();
//question 15
void countNode();
//question 16
void countOccur();
//question 17
void modifyByAttrib();
//question 18
void sortByAttrib();//----------------------------------------main sort function--------------------------//
void charSorter(char text[], int order);//--sub sort func
void durSorter(int order);//--sub sort func
void yearSorter(int order);//--sub sort func
//question 19
void dispTop();

//----------------///Suplementary functions we used for other purposes///---------------//

inline void operationEnd(){cout<<"\n >>press any key to continue....";getch();}
void dispFrmArg(music *oneMusic);
int nodeCounterForTop();

////-------------////////A function for the sample data so that a user can choose any amount of music not exceeding 40////-----------------------------------
musicsample musicArray[40];

void storeAtIndex(musicsample & somemusic, string musicID_1, string title_1, string artist_1, string musicgenre_1, int yearReleased_1,float musicDuration_1){
strcpy(somemusic.musicID,musicID_1.c_str());
strcpy(somemusic.title,title_1.c_str());
strcpy(somemusic.artist,artist_1.c_str());
strcpy(somemusic.genre,musicgenre_1.c_str());
somemusic.yearReleased=yearReleased_1;
somemusic.duration=musicDuration_1;
}
void thesamplemusics(){
    storeAtIndex(musicArray[0],"MLMS01","Kal","Rophnan","EDM",2014,3.52);
	storeAtIndex(musicArray[1],"MLMS02","Bihon","Rophnan","EDM",2014,3.22);
	storeAtIndex(musicArray[2],"MLMS03","Rega","Jano-Band","Rock",2011,4.05);
	storeAtIndex(musicArray[3],"MLMS04","Hiwot","Rophnan","EDM",2012,2.46);
	storeAtIndex(musicArray[4],"MLMS05","Bati","Chelina","Bati",2012,3.33);
	storeAtIndex(musicArray[5],"MLMS06","Walia","Tedy-Afro","Reggae",2005,3.35);
	storeAtIndex(musicArray[6],"MLMS07","Ayzon","Chelina","Pop",2012,3.55);
	storeAtIndex(musicArray[7],"MLMS08","Tsedal","Bek-geez","EDM",2011,3.44);
	storeAtIndex(musicArray[8],"MLMS09","Piyassa","Rophnan","EDM",2012,4.12);
	storeAtIndex(musicArray[9],"MLMS10","Kal","Rophnan","EDM",2014,4.36);
	storeAtIndex(musicArray[10],"MLMS11","Sai-Bai","Chelina","Pop",2012,3.54);
	storeAtIndex(musicArray[11],"MLMS12","Na-Na","Hewan","Edm",2013,4.31);
	storeAtIndex(musicArray[12],"MLMS13","Tetefafan","Haleluya","Pop",2013,4.12);
	storeAtIndex(musicArray[13],"MLMS14","Atgebam","Lij-Michael","Rap",2014,3.52);
	storeAtIndex(musicArray[14],"MLMS15","Weghat","Rophnan","EDM",2014,3.52);
	storeAtIndex(musicArray[15],"MLMS16","Nanye","Lij-Michael","Rap",2014,3.52);
	storeAtIndex(musicArray[16],"MLMS17","Essey","Rophnan","EDM",2014,2.45);
	storeAtIndex(musicArray[17],"MLMS18","Kuchit","Veronica","Pop",2014,3.43);
	storeAtIndex(musicArray[18],"MLMS19","Ney-Enega","Nahom","Latin",2013,3.11);
	storeAtIndex(musicArray[19],"MLMS20","Almetam","Tedy-Yoo","Rap",2014,2.58);
	storeAtIndex(musicArray[20],"MLMS21","Ayrak","Jano-Band","Rock",2005,5.51);
	storeAtIndex(musicArray[21],"MLMS22","Endegena","Mahmud","Tizita",1992,4.14);
	storeAtIndex(musicArray[22],"MLMS23","Na'et","Tedy-Afro","Reggae",2014,6.26);
	storeAtIndex(musicArray[23],"MLMS24","Zora","Yared-Negu","Pop",2013,4.44);
	storeAtIndex(musicArray[24],"MLMS25","Mare","Esubalew","Pop",2008,4.07);
	storeAtIndex(musicArray[25],"MLMS26","Anmogn","Chelina","Pop",2013,2.58);
	storeAtIndex(musicArray[26],"MLMS27","Melkam","Chelina","Reggae",2004,4.52);
	storeAtIndex(musicArray[27],"MLMS28","Adimera","Yared-Negu","Pop",2011,5.15);
	storeAtIndex(musicArray[28],"MLMS29","Gonay","Chelina","Pop",2013,3.11);
	storeAtIndex(musicArray[29],"MLMS30","Ane","Hewan","Rock",2010,3.59);
	storeAtIndex(musicArray[30],"MLMS31","Yinegal","Jano-Band","Rock",2014,4.36);
	storeAtIndex(musicArray[31],"MLMS32","Kal","Hewan","EDM",2014,3.52);
	storeAtIndex(musicArray[32],"MLMS33","Feyamo","Jahlude","Reggae",2014,4.14);
	storeAtIndex(musicArray[33],"MLMS34","Munaye","Hewan","Pop",2014,4.48);
	storeAtIndex(musicArray[34],"MLMS35","Godanaw","Jahlud","Reggae",2014,3.01);
	storeAtIndex(musicArray[35],"MLMS36","Anchi-Yene","Sami-Dan","Pop",2008,5.03);
	storeAtIndex(musicArray[36],"MLMS37","Kurfiya","Veronica","Pop",2014,4.18);
	storeAtIndex(musicArray[37],"MLMS38","Gamo-Dare","Rophnan","EDM",2010,4.22);
	storeAtIndex(musicArray[38],"MLMS39","Yesew-Nesh","Sami-Dan","Pop",2014,4.30);
	storeAtIndex(musicArray[39],"MLMS40","Metahu","Jahlud","Reggae",2005,4.28);
}
//the function that lets the user choose any amount of musics from the sample we created;
void selfGenSample(){
	thesamplemusics();
	music *traverser=new music;
	traverser=start;
    cout<<"how many music samples do you want:\n>>";
    int x; cin>>x;
    if (x>40||x<1)while(x>40||x<1){cout<<"Enter only between 1 and 40. We have only 40 musics\n>>";cin>>x;}
    for (int i=0;i<x;i++){
        music *newmusicsample=new music;
        strcpy(newmusicsample->artist,musicArray[i].artist);
        strcpy(newmusicsample->musicID,musicArray[i].musicID);
        strcpy(newmusicsample->genre,musicArray[i].genre);
        strcpy(newmusicsample->title,musicArray[i].title);
        newmusicsample->duration=musicArray[i].duration;
        newmusicsample->yearReleased=musicArray[i].yearReleased;
        newmusicsample->next=NULL;
        if(start==NULL){
			start=newmusicsample;
        }
        else{
   		    music *traverser=start;
        	for(;traverser->next!=NULL;traverser=traverser->next){}
        	traverser->next=newmusicsample;
		}
	}
	cout<<"Sample created successfully. Now you can do what you want with it.";
}
//---------------------------//Validator//---------------------------------------------------------
int validator(){
		string number;
		cin>>number;
		int len=number.length();
		int x;
		int yesChar=0;
		for(int i=0;i<len;i++){
		if(isdigit(number[i])){}
		else{
		yesChar=1;}
		}
		if (yesChar==1)while(yesChar==1){
		cout<<"please enter positive integer only\n>>";
		cin>>number;
		len=number.length();
		yesChar=0;
		for(int i=0;i<len;i++){
		if(isdigit(number[i])){}
		else{
		yesChar=1;
		}
		}
	}	
		x=0;
		int j=1;
		for(len=len-1;len>=0;len--){
			x+=(number[len]-48)*j;
			j*=10;
		}
		return x;
}

float floatValidator(){
	int x=1;
	float num;
	cin>>num;
		if(cin.fail()){
		cin.clear();
		cin.ignore();
		x=0;
		}
	while(x==0){
		x=1;
		cout<<"please enter a float only\n>>";
		cin>>num;
		if(cin.fail()){
		cin.clear();
		cin.ignore();
		x=0;
		}
	}
	return num;
}
/*
##########################################
------------Main function----------------
##########################################
*/
int main()
{
while(true)
	{
    cout<<"\n\n\t==================================================================\n\t----------Data Structure and Algorithm Group Assignment-----------\n\t==================================================================\n";
	cout<<"\t||\t\t\t\t\t\t\t\t||\n\t||\t**********************************************\t\t||";
	cout<<"\n\t||\t######---Music List Management System---######\t\t||";
	cout<<"\n\t||\t**********************************************\t\t||";
    cout<<"\n\t||\t\t\t\t\t\t\t\t||\n\t||\t   (((Implementation - singly linked list))\t\t||\n";
    cout<<"\t__________________________________________________________________\n\n";
	//dialogue
    cout<<">>choose what you want to do from the given alternatives\n\n";
    cout<<" 1.  Insert at the beginning of linked list\n";
    cout<<" 2.  Insert at the end of linked list\n";
    cout<<" 3.  Insert at the middle of linked list. \n";
    cout<<" 4.  Delete the first element in your linked list\n";
    cout<<" 5.  Delete the last element in your linked list\n";
    cout<<" 6.  Delete a node with an attribute you provide\n";
    cout<<" 7.  Delete nth Node\n";
    cout<<" 8.  Search and find a music with MINIMUM amount of duration\n";
    cout<<" 9.  Search and find a music with MAXIMUM amount of duration\n";
    cout<<" 10. Calculate average duration of all the musics in the list\n\t(Since a year can't have an average, next question is skipped and we  added #20 instead of that.)\n";
    cout<<" 11. A function that can delete a music having MINIMUM amount of duration\n";
    cout<<" 12. A function that can delete a music having MAXIMUM amount of duration\n";
	cout<<" 13. Search a music with any attribute found in the structure\n";
	cout<<" 14. Display information of all musics in your linked list\n";
	cout<<" 15. Count and tell the number of nodes in your linked list\n";
	cout<<" 16. Count the number of occurence of a certain value of an attribute in the list\n";
	cout<<" 17. Modify any attribute of any music item\n";S
	cout<<" 18. Sort the list of musics by any attribute\n";
	cout<<" 19. Display top musics using their attributes as a criteria\n";
	cout<<" 20. !!! If you don't want to enter data manually you can choose this option to use the sample we created.\n>>";
	int choisenumber=validator();
	if(choisenumber<1||choisenumber>20)while(choisenumber<1||choisenumber>20){
		cout<<"please between 1 and 20\n>>";
		choisenumber=validator();
	}
	if(choisenumber==1){insertAtBeginning();operationEnd();}
    else if(choisenumber==2){insertAtEnd();operationEnd();}
    else if(choisenumber==3){insertAtMiddle();operationEnd();}
    else if(choisenumber==4){deleteFirst(); operationEnd();}
    else if(choisenumber==5){deleteLast(); operationEnd();}
    else if(choisenumber==6){deleteNodeAttrib();operationEnd();}
    else if(choisenumber==7){deleteNthNode();operationEnd();}
    else if(choisenumber==8){searchMin(); operationEnd();}
    else if(choisenumber==9){searchMax(); operationEnd();}
    else if(choisenumber==10){average(); operationEnd();}
    else if(choisenumber==11){deleteMin();operationEnd();}
    else if(choisenumber==12){deleteMax();operationEnd();}
    else if(choisenumber==13){searchByAttrib();operationEnd();}
    else if(choisenumber==14){displayAll(); operationEnd();}
    else if(choisenumber==15){countNode(); operationEnd();}
    else if(choisenumber==16){countOccur();operationEnd();}
    else if(choisenumber==17){modifyByAttrib(); operationEnd();	}
    else if(choisenumber==18){sortByAttrib(); operationEnd();}
    else if(choisenumber==19){dispTop();operationEnd();}
    else if(choisenumber==20){selfGenSample();operationEnd();}
    else {cout<<"!!!wrong input. Enter between 1 and 20.";operationEnd();}
	}
}
/*
########################################################
----------------functions for Question 1----------------
########################################################
*/
void insertAtBeginning(){
    cout<<"Enter how many musics you want to add in your list: \n>>";
	int x=validator();
    for (int i=0;i<x;i++){
        music *newmusic=new music;
        cout<<"\nEnter a unique ID for music "<<i+1<<":\n>> ";
//*******************************///cheking if the entered ID is not already in the list
		int idExist=0;
		char idToCompare[20]; cin>>idToCompare;
		if(start==NULL){strcpy(newmusic->musicID,idToCompare);		}
		else{
			music *finder=start;
			for(;finder->next!=NULL;finder=finder->next)
				{
					if(strcmp(finder->musicID,idToCompare)==0){	cout<<"Id exist. please enter another ID\n"; idExist=1;}
				}
					if(strcmp(finder->musicID,idToCompare)==0){	cout<<"Id exist. please enter another ID\n"; idExist=1;}
					else{strcpy(newmusic->musicID,idToCompare);}
			}
		if(idExist==1){i--;continue;}
        cout<<"Enter Title for your music:\n>> ";cin>>newmusic->title;
        cout<<"The Name of the artist:\n>> ";cin>>newmusic->artist;
		cout<<"The genre of the music:\n>> ";cin>>newmusic->genre;
		cout<<"Duration of the song. eg. 3.53 means 3 minutes and 53 seconds:\n>> ";
//*******************************//here validating whether the entered duration of the music is appropriate or not
		float dur=floatValidator();
		if (dur>20||dur<1)while(dur>20||dur<1){cout<<"Sorry the duration must be only between 1 and 20: \n>>";dur=floatValidator();}
		newmusic->duration=dur;//validation complete and duration entered
		cout<<"Year Released: \n>>";
//******************************//here validating the entered year
		int yr=validator();
		if (yr>2022||yr<1800)while(yr>2022||yr<1800){cout<<"The year must be only between 1800 and 2022: \n>>";yr=validator();}
		newmusic->yearReleased=yr;//validation complete and year entered
        newmusic->next=NULL;
        if(start==NULL){
			start=newmusic;
        }
        else{
        	newmusic->next=start;
        	start=newmusic;
		}
    }
}
/*
########################################################
----------------functions for Question 2----------------
########################################################
*/
void insertAtEnd(){
    cout<<"Enter how many musics you want to add in your list:\n>> ";
    int x=validator();
    for (int i=0;i<x;i++){
        music *newmusic=new music;
        cout<<"\nEnter a unique ID for music "<<i+1<<":\n>> ";
//*******************************///cheking if the entered ID is not already in the list
		int idExist=0;
		char idToCompare[20]; cin>>idToCompare;
		if(start==NULL){strcpy(newmusic->musicID,idToCompare);		}
		else{
			music *finder=start;
			for(;finder->next!=NULL;finder=finder->next)
				{
					if(strcmp(finder->musicID,idToCompare)==0){	cout<<"Id exist. please enter another ID\n"; idExist=1;}
				}

					if(strcmp(finder->musicID,idToCompare)==0){	cout<<"Id exist. please enter another ID\n"; idExist=1;}
					else{strcpy(newmusic->musicID,idToCompare);}
			}
		if(idExist==1){i--;continue;}
        cout<<"Enter Title for your music:\n>> ";cin>>newmusic->title;
        cout<<"The Name of the artist:\n>> ";cin>>newmusic->artist;
		cout<<"The genre of the music:\n>> ";cin>>newmusic->genre;
		cout<<"Duration of the song. eg. 3.53 means 3 minutes and 53 seconds: \n>>";
//*******************************//here validating whether the entered duration of the music is appropriate or not
		float dur=floatValidator();
		if (dur>20||dur<1)while(dur>20||dur<1){cout<<"Sorry the duration must be only between 1 and 20: \n>>";dur=floatValidator();	}
		newmusic->duration=dur;
		cout<<"Year Released:\n>> ";
//******************************//here validating the entered year
		int yr=validator();
		if (yr>2022||yr<1800)while(yr>2022||yr<1800){cout<<"The year must be only between 1800 and 2022: \n>>";yr=validator();}
		newmusic->yearReleased=yr;//validation complete and year entered
        newmusic->next=NULL;
        if(start==NULL){
			start=newmusic;
        }
        ////The only difference between function 1 and this function is here:
        else{ music *traverser=start;
        	for(;traverser->next!=NULL;traverser=traverser->next){}
        	traverser->next=newmusic;
		}
    }
}
/*
########################################################
----------------functions for Question 3----------------
########################################################
*/
void insertAtMiddle()
{
char titlebuffer[40];
int x;

if(start==NULL){cout<<"list is empty!!! first add some items and then comeback.";	}
else
	{
	cout<<"after which music do you want to insert your music in. Just enter music title:\n>> "; cin>>titlebuffer;
		//validating if the entered name is found in the list
		music *find=start;
		for(;find->next!=NULL;find=find->next)
			{
				if(strcmp(find->title,titlebuffer)==0)
					{
						cout<<"Enter how many musics you want to add between your list:\n>> "; x=validator();
						music *nexttemp=find->next;
					    for (int i=0;i<x;i++){
			        	music *newmusic=new music;

			        	cout<<"\nEnter a unique ID for music "<<i+1<<": \n>>";
//*******************************///cheking if the entered ID is not already in the list
						int idExist=0;
						char idToCompare[20]; cin>>idToCompare;
						if(start==NULL){strcpy(newmusic->musicID,idToCompare);		}
						else{
							music *finder=start;
							for(;finder->next!=NULL;finder=finder->next)
							{
								if(strcmp(finder->musicID,idToCompare)==0){	cout<<"Id exist. please enter another ID\n"; idExist=1;}
							}
								if(strcmp(finder->musicID,idToCompare)==0){	cout<<"Id exist. please enter another ID\n"; idExist=1;}
								else{strcpy(newmusic->musicID,idToCompare);}
							}
						if(idExist==1){i--;continue;}
			        	cout<<"Enter Title for your music:\n>> ";cin>>newmusic->title;
			        	cout<<"The Name of the artist:\n>> ";cin>>newmusic->artist;
						cout<<"The genre of the music:\n>> ";cin>>newmusic->genre;
						cout<<"Duration of the song. eg. 3.53 means 3 minutes and 53 seconds:\n>>";
//*******************************//here validating whether the entered duration of the music is appropriate or not
						float dur=floatValidator();
						if (dur>20||dur<1)while(dur>20||dur<1){cout<<"Sorry the duration must be only between 1 and 20:\n>> ";dur=floatValidator();}
						newmusic->duration=dur;
						cout<<"Year Released:\n>> ";
						//******************************//here validating the entered year
						int yr=validator();
						if (yr>2022||yr<1800)while(yr>2022||yr<1800){cout<<"The year must be only between 1800 and 2022: \n>>";yr=validator();}
						newmusic->yearReleased=yr;//validation complete and year entered
						find->next=newmusic;
						find=newmusic;
						newmusic->next=nexttemp;
						}
						break;
					}
				}
				if(find->next==NULL)
				{
					if(strcmp(find->title,titlebuffer)==0)
					{
cout<<"the item you intered is found at the last. Do you want to add it there?\n1.yes\n2.no";
						int x;cin>>x;
						if(x==1){insertAtEnd();}
					}
					else cout<<"A music with a name you provided not found. Try again with the right name";
				}
	}
}
/*
########################################################
----------------functions for Question 4----------------
########################################################
*/
void deleteFirst(){
	if(start==NULL){cout<<"The list is empty add some items first";	}
	else{
	music *tobeDeleted=start;
	start=start->next;
	tobeDeleted->next=NULL;
	delete tobeDeleted;
	cout<<"\nFirst Music Deleted successfully";
	}
}
/*
########################################################
----------------functions for Question 5----------------
########################################################
*/
void deleteLast(){
	if(start==NULL){cout<<"The list is empty add some items first";	}
	else{
	music *lastElement=start;
	music *temp=lastElement->next;
	for(;temp->next!=NULL;){
	lastElement=lastElement->next;
	temp=lastElement->next;
	}
	lastElement->next=NULL;
	delete temp;
	cout<<"\nLast Music Deleted successfully. Now you can check by pressing number 14";
}
}
/*
########################################################
----------------functions for Question 6----------------
########################################################
*/
void deleteNodeAttrib(){
	if(start==NULL){
		cout<<"List is empty add some items first";
	}
	else{
	cout<<"By which attribute do you want to delete an item?\n";
	cout<<"1. Delete by ID\n2. Delete by title\n3. Delete by Artist name\n4. Delete by genre\n5. Delete by Duration of the music\n6. Delete by Year Released \n>>";
	int x=validator();
	if (x>6||x<1)while(x>6||x<1){cout<<"Enter only between 1 and 6.\n>>";x=validator();}

	//delete By ID
	if (x==1){
	cout<<"enter the ID of the music you want to delete\n>>";
	char id[20];cin>>id;
	//checking whether id exists
			music *finder=new music;
			int idExist=0;
			//validating the id exists in the list
			for(finder=start;finder->next!=NULL;finder=finder->next){
				if(strcmp(finder->musicID,id)==0) idExist=1;
			}
			if(strcmp(finder->musicID,id)==0) idExist=1;
			if(idExist==0)while(idExist==0){
				cout<<"ID doesn't Exist in the list, Please try again with another one\n>>";
				cin>>id;
				for(finder=start;finder->next!=NULL;finder=finder->next){
				if(strcmp(finder->musicID,id)==0) idExist=1;
				}
				if(strcmp(finder->musicID,id)==0) idExist=1;
			}
			//cheking id exist complete
			if(start->next==NULL){
			cout<<"The ID you entered is found at first and there is only one music";deleteFirst();
			}
			else{

				if(strcmp(start->musicID,id)==0){
				cout<<"The ID you entered is found at first";deleteFirst();
				}
				else{
				music *toBeDeleted=new music;
				music *follower=new music;
				for(finder=start;finder->next!=NULL;){
					follower=finder;
					finder=finder->next;
					if(strcmp(finder->musicID,id)==0){
						toBeDeleted=finder;
						follower->next=toBeDeleted->next;
						toBeDeleted->next=NULL;
						delete toBeDeleted;
					}
				}
				cout<<"Deleting the music with the ID "<<id<<" success.";
			}
			}
			}
	//delete By title
	else if(x==2){
			cout<<"enter the title of the music you want to delete\n>>";
			char title[40];cin>>title;
			//checking whether title exists
			music *finder=new music;
			int Exist=0;
			for(finder=start;finder->next!=NULL;finder=finder->next){
				if(strcmp(finder->title,title)==0) Exist=1;
			}
			if(strcmp(finder->title,title)==0) Exist=1;
			if(Exist==0)while(Exist==0){
				cout<<"The title you entered doesn't Exist in the list, Please try again with another one\n>>";
				cin>>title;
				for(finder=start;finder->next!=NULL;finder=finder->next){
				if(strcmp(finder->title,title)==0) Exist=1;
				}
				if(strcmp(finder->title,title)==0) Exist=1;
			}
			//cheking complete
			if(start->next==NULL){
				cout<<"the music a title "<<title<<" found at first and its the only music in the list";
				deleteFirst();
			}
			else{
			int deleted=0;
			while(deleted==0){
				deleted=1;
				if(strcmp(start->title,title)==0){
					music *toBeDeleted=new music;
					toBeDeleted=start;
					start=start->next;
					toBeDeleted->next=NULL;
					delete toBeDeleted;
					deleted=0;
					}
				else{
					music *finder=new music;
					music *follower=new music;
					for(finder=start;finder->next!=NULL;){
						int yesdeleted=0;
						follower=finder;
						finder=finder->next;
						if(strcmp(finder->title,title)==0){
							music *toBeDeleted=new music;
							toBeDeleted=finder;
							follower->next=finder->next;
							toBeDeleted->next=NULL;
							delete toBeDeleted;
							yesdeleted=1;
						}
						if(yesdeleted==1) {deleted=0;break;}

						}
					}
				}
				cout<<"deleted all musisc with the title '"<<title<<"' successfully";

		}
		}
	else if(x==3){
			cout<<"enter the Artist name of the music you want to delete\n>>";
			char artist[30];cin>>artist;
			//checking whether artist exists
			music *finder=new music;
			int Exist=0;
			for(finder=start;finder->next!=NULL;finder=finder->next){
				if(strcmp(finder->artist,artist)==0) Exist=1;
			}
			if(strcmp(finder->artist,artist)==0) Exist=1;
			if(Exist==0)while(Exist==0){
				cout<<"The Artist name you entered doesn't Exist in the list, Please try again with another one\n>>";
				cin>>artist;
				for(finder=start;finder->next!=NULL;finder=finder->next){
				if(strcmp(finder->artist,artist)==0) Exist=1;
				}
				if(strcmp(finder->artist,artist)==0) Exist=1;
			}
			//cheking complete
			if(start->next==NULL){
				cout<<"the music an Artist name is "<<artist<<" found at first and its the only music in the list";
				deleteFirst();
			}
			else{
			int deleted=0;
			while(deleted==0){
				deleted=1;
				if(strcmp(start->artist,artist)==0){
					music *toBeDeleted=new music;
					toBeDeleted=start;
					start=start->next;
					toBeDeleted->next=NULL;
					delete toBeDeleted;
					deleted=0;
					}
				else{
					music *finder=new music;
					music *follower=new music;
					for(finder=start;finder->next!=NULL;){
						int yesdeleted=0;
						follower=finder;
						finder=finder->next;
						if(strcmp(finder->artist,artist)==0){
							music *toBeDeleted=new music;
							toBeDeleted=finder;
							follower->next=finder->next;
							toBeDeleted->next=NULL;
							delete toBeDeleted;
							yesdeleted=1;
						}
						if(yesdeleted==1) {deleted=0;break;}

						}
					}
				}
				cout<<"deleted all musisc with the Artist name '"<<artist<<"' successfully";
		}
		}
			else if(x==4){
			cout<<"enter the genre of the music you want to delete\n>>";
			char genre[40];cin>>genre;
			//checking whether genre exists
			music *finder=new music;
			int Exist=0;
			for(finder=start;finder->next!=NULL;finder=finder->next){
				if(strcmp(finder->genre,genre)==0) Exist=1;
			}
			if(strcmp(finder->genre,genre)==0) Exist=1;
			if(Exist==0)while(Exist==0){
				cout<<"The genre you entered doesn't Exist in the list, Please try again with another one\n>>";
				cin>>genre;
				for(finder=start;finder->next!=NULL;finder=finder->next){
				if(strcmp(finder->genre,genre)==0) Exist=1;
				}
				if(strcmp(finder->genre,genre)==0) Exist=1;
			}
			//cheking complete
			if(start->next==NULL){
				cout<<"the music a genre is "<<genre<<" found at first and its the only music in the list";
				deleteFirst();
			}
			else{
			int deleted=0;
			while(deleted==0){
				deleted=1;
				if(strcmp(start->genre,genre)==0){
					music *toBeDeleted=new music;
					toBeDeleted=start;
					start=start->next;
					toBeDeleted->next=NULL;
					delete toBeDeleted;
					deleted=0;
					}
				else{
					music *finder=new music;
					music *follower=new music;
					for(finder=start;finder->next!=NULL;){
						int yesdeleted=0;
						follower=finder;
						finder=finder->next;
						if(strcmp(finder->genre,genre)==0){
							music *toBeDeleted=new music;
							toBeDeleted=finder;
							follower->next=finder->next;
							toBeDeleted->next=NULL;
							delete toBeDeleted;
							yesdeleted=1;
						}
						if(yesdeleted==1) {deleted=0;break;}

						}
					}
				}
				cout<<"deleted all musisc with the genre name '"<<genre<<"' successfully";
		}
		}
			else if(x==5){
			cout<<"enter the Duration of the music you want to delete(format=min.sec)(eg 4.23)\n>>";
			float duration=floatValidator();
			//checking whether duration exists
			music *finder=new music;
			int Exist=0;
			for(finder=start;finder->next!=NULL;finder=finder->next){
				if(finder->duration==duration)Exist=1;
			}
			if(finder->duration==duration)Exist=1;
			//Full Validation here
			if(Exist==0||duration>20||duration<1)while(Exist==0||duration>20||duration<10){
				if(duration>20||duration<1)
				cout<<"The Duration you entered is out of range. please try between 1 and 20\n>>";
				else if(Exist==0){
				cout<<"The Duration you entered doesn't Exist in the list, Try another one\n>>";
				}
				duration=floatValidator();
				for(finder=start;finder->next!=NULL;finder=finder->next){
				if(finder->duration==duration)Exist=1;
				}
				if(finder->duration==duration)Exist=1;
			}
			//cheking complete
			if(start->next==NULL){
				cout<<"the music a duration is "<<duration<<" found at first and its the only music in the list";
				deleteFirst();
			}
			else{
			int deleted=0;
			while(deleted==0){
				deleted=1;
				if(start->duration==duration){
					music *toBeDeleted=new music;
					toBeDeleted=start;
					start=start->next;
					toBeDeleted->next=NULL;
					delete toBeDeleted;
					deleted=0;
					}
				else{
					music *finder=new music;
					music *follower=new music;
					for(finder=start;finder->next!=NULL;){
						int yesdeleted=0;
						follower=finder;
						finder=finder->next;
						if(finder->duration==duration){
							music *toBeDeleted=new music;
							toBeDeleted=finder;
							follower->next=finder->next;
							toBeDeleted->next=NULL;
							delete toBeDeleted;
							yesdeleted=1;
						}
						if(yesdeleted==1) {deleted=0;break;}
						}
					}
				}
				cout<<"deleted all musisc with a duration '"<<duration<<"' successfully";
		}
		}
			else if(x==6){
			cout<<"enter the the release year of the music you want to delete\n>>";
			int yearReleased=validator();
			//checking whether year exists
			music *finder=new music;
			int Exist=0;
			for(finder=start;finder->next!=NULL;finder=finder->next){
				if(finder->yearReleased==yearReleased)Exist=1;
			}
			if(finder->yearReleased==yearReleased)Exist=1;
			//Full Validation here
			if(Exist==0||yearReleased>2022||yearReleased<1800)while(Exist==0||yearReleased>2022||yearReleased<1800){
				if(yearReleased>2022||yearReleased<1800)
				cout<<"The year of music release you entered is out of range. please try between 1800 and 2022\n>>";
				else if(Exist==0){
				cout<<"The year of music release you entered doesn't Exist in the list, Please try again with another one\n>>";
				}
				yearReleased=validator();
				for(finder=start;finder->next!=NULL;finder=finder->next){
				if(finder->yearReleased==yearReleased)Exist=1;
				}
				if(finder->yearReleased==yearReleased)Exist=1;
			}
			//cheking complete
			if(start->next==NULL){
				cout<<"the music a release year "<<yearReleased<<" is found at first and its the only music in the list";
				deleteFirst();
			}
			else{
			int deleted=0;
			while(deleted==0){
				deleted=1;
				if(start->yearReleased==yearReleased){
					music *toBeDeleted=new music;
					toBeDeleted=start;
					start=start->next;
					toBeDeleted->next=NULL;
					delete toBeDeleted;
					deleted=0;
					}
				else{
					music *finder=new music;
					music *follower=new music;
					for(finder=start;finder->next!=NULL;){
						int yesdeleted=0;
						follower=finder;
						finder=finder->next;
						if(finder->yearReleased==yearReleased){
							music *toBeDeleted=new music;
							toBeDeleted=finder;
							follower->next=finder->next;
							toBeDeleted->next=NULL;
							delete toBeDeleted;
							yesdeleted=1;
						}
						if(yesdeleted==1) {deleted=0;break;}

						}
					}
				}
				cout<<"deleted all musisc which were released in '"<<yearReleased<<"' successfully";
		}
		}
	}
}
/*
########################################################
----------------functions for Question 7----------------
########################################################
*/
void deleteNthNode(){
		if (start==NULL){ cout<<"list is empty add some musics first";
	}
	else{
	cout<<"enter which nth node you want to delete? enter a number: \n>>";
	int x=validator();
	music *finder=new music;
	music *follower=new music;
	int count=1;
	finder=start;
	follower=finder;
	for(;finder->next!=NULL&&count<x;count++,finder=finder->next){
	follower=finder;
	}
	if(finder->next==NULL&&count==x){
		cout<<"you requested to delete the last music\n";
		deleteLast();
	}
	else if(finder->next==NULL&&count<x){
		cout<<"There is no such amount in the list";
	}
	else if(finder->next!=NULL&&count==x){
		if(strcmp(finder->musicID,start->musicID)==0){
		cout<<"you requested to delete the first music\n";
		deleteFirst();
		}
		else{
		follower->next=finder->next;
		finder->next==NULL;
		delete finder;
		cout<<"successfully deleted the music you requested";
		}
	}
	else{
		cout<<"unknown error";
	}
	}
}
/*
########################################################
----------------functions for Question 8----------------
########################################################
*/
void searchMin(){
	if (start==NULL){ cout<<"list is empty add some musics first";
	}
	else{
	music *finder=new music;
	music *min=new music;
	min = start;
	for(finder=start;finder->next!=NULL;finder=finder->next){
		if(finder->duration<min->duration) min=finder;
	}
	if(finder->duration<min->duration) min=finder;
	cout<<"The music with the least Duration is: \n";
	dispFrmArg(min);
	}
}
/*
########################################################
----------------functions for Question 9----------------
########################################################
*/
void searchMax(){
	if (start==NULL){ cout<<"list is empty add some musics first";
	}
	else{
	music *finder=new music;
	music *max=new music;
	max = start;
	for(finder=start;finder->next!=NULL;finder=finder->next){
		if(finder->duration>max->duration) max=finder;
	}
	if(finder->duration>max->duration) max=finder;
	cout<<"The music with the longest Duration is: \n";
	dispFrmArg(max);
	}
}
/*
#########################################################
----------------functions for Question 10----------------
#########################################################
*/
void average(){
	if(start==NULL) cout<<"list is empty please add some musics first";
	else{
	if (start->next==NULL){
	int minute = start->duration;
	int second = (start->duration-float(minute))*100;
	cout<<"The average duration is: "<<minute<<" minute and "<<second<<" second";
	}
	else{
	int minbuff=0, counter=1;
	float secbuff=0.0;
	music *finder=new music;
	for(finder=start;finder->next!=NULL;finder=finder->next)
	{
	counter++;
	int min=finder->duration;
	float sec=finder->duration-min;////for all the items except the last
	minbuff+=min;
	secbuff+=sec;
	}
	counter++;
	int min=finder->duration;
	float sec=finder->duration-min;//// for the last item in the list
	minbuff+=min;
	secbuff+=sec;
	secbuff*=100;
	minbuff*=60;
	float total=float(minbuff)+secbuff;
	float average=total/float(counter);
	//conversion from seconds into minutes and seconds
	int minute=int(average)/60;
	int second=int(average)%60;
//	int second=average-(minute*counter);
	cout<<"The average duration is: "<<minute<<" minute and "<<second<<" second";
}}}
/*
#########################################################
----------------functions for Question 11----------------
#########################################################
*/
void deleteMin(){
		if(start==NULL){
		cout<<"List is empty add some items first";
}
	else{
	if(start->next==NULL){
	int minute = start->duration;
	int second = (start->duration-float(minute))*100;
	cout<<"only one music is found in the list\nits duration is: "<<minute<<" minute and "<<second<<" second";
	deleteFirst();
	}
	else{
		music *finder=new music;
		music *follower=new music;
		music *min=new music;
		float minimum=start->duration;
		for(finder=start;finder->next!=NULL;finder=finder->next){
			if(minimum>finder->duration){
				minimum=finder->duration;
			}
		}
		if(minimum>finder->duration)
				minimum=finder->duration;
		if(minimum==start->duration){
			cout<<"the music with a minimum duration is found at first";
			deleteFirst();
		}
		else{
			min=start;
			for(finder=start;finder->next!=NULL;){
				follower=finder;
				finder=finder->next;
				if(minimum==finder->duration){
					min=follower;
					music *toBeDeleted=new music;
					toBeDeleted=finder;
					min->next=toBeDeleted->next;
					toBeDeleted->next=NULL;
					delete toBeDeleted;
					}
			}
			cout<<"Deleting the music the minimum duration successful";
		}
		}
	}
	}
/*
#########################################################
----------------functions for Question 12----------------
#########################################################
*/
void deleteMax(){
		if(start==NULL){
		cout<<"List is empty add some items first";
}
	else{
	if(start->next==NULL){
	int minute = start->duration;
	int second = (start->duration-float(minute))*100;
	cout<<"only one music is found in the list\nits duration is: "<<minute<<" minute and "<<second<<" second";
	deleteFirst();
	}
	else{
		music *finder=new music;
		music *follower=new music;
		music *max=new music;
		float maximum=start->duration;
		for(finder=start;finder->next!=NULL;finder=finder->next){
			if(maximum<finder->duration){
				maximum=finder->duration;
			}
		}
		if(maximum<finder->duration)
				maximum=finder->duration;
		if(maximum==start->duration){
			cout<<"the music with a Maximum duration is found at first";
			deleteFirst();
		}
		else{
			max=start;
			for(finder=start;finder->next!=NULL;){
				follower=finder;
				finder=finder->next;
				if(maximum==finder->duration){
					max=follower;
					music *toBeDeleted=new music;
					toBeDeleted=finder;
					max->next=toBeDeleted->next;
					toBeDeleted->next=NULL;
					delete toBeDeleted;
					}
			}
			cout<<"Deleting the music the Maximum duration successful";
		}
		}
	}
	}
/*
#########################################################
----------------functions for Question 13----------------
#########################################################
*/
void searchByAttrib(){
	if(start==NULL){
		cout<<"List is empty add some items first";
	}
	else{
	cout<<"by which attribute you want to search your music?\n";
	cout<<"1. Search by ID\n2. Search by title\n3. Search by Artist name\n4. Search by genre \n5. Search by Duration of the music\n6. Search by Year Released\n>>";
	int x=validator();
	if (x>6||x<1)while(x>6||x<1){cout<<"Enter only between 1 and 6.\n>>";x=validator();}

	//by ID
	if (x==1)
		{
			int found=0, i=1;music *finder;
			cout<<"enter the ID of the Music you want to Search:\n>> ";char id[20];cin>>id;
			for(finder=start;finder->next!=NULL;finder=finder->next)
				{
				if(strcmp(finder->musicID,id)==0)
					{
					found=1;
					cout<<"Music "<<i<<":\n";dispFrmArg(finder);//for displaying
					i++;
					}
				}
				if(strcmp(finder->musicID,id)==0)
				{
				cout<<"Music "<<i<<":\n"; dispFrmArg(finder);
				}

			if (found==0) cout<<"A music with such ID doesn't exist";
		}
	else if(x==2)
		{
			int found=0, i=1;music *finder;
			cout<<"enter the Title of the Music you want to Search:\n>> ";char titleBuffer[40];cin>>titleBuffer;
			for(finder=start;finder->next!=NULL;finder=finder->next)
				{
				if(strcmp(finder->title,titleBuffer)==0)
					{
					found=1;
					cout<<"Music "<<i<<":\n";dispFrmArg(finder);//for displaying
					i++;
					}
				}
				if(strcmp(finder->title,titleBuffer)==0)
				{
				cout<<"Music "<<i<<":\n"; dispFrmArg(finder);
				}
			if (found==0) cout<<"A music with such Title doesn't exist";
		}
		else if(x==3)
		{
			int found=0, i=1;music *finder;
			cout<<"enter the name of the Artist you want to Search:\n>> ";char artistBuffer[30];cin>>artistBuffer;
			for(finder=start;finder->next!=NULL;finder=finder->next)
				{
				if(strcmp(finder->artist,artistBuffer)==0)
					{
					found=1;
					cout<<"Music "<<i<<":\n";dispFrmArg(finder);//for displaying
					i++;
					}
				}
				if(strcmp(finder->artist,artistBuffer)==0)
				{
				cout<<"Music "<<i<<":\n"; dispFrmArg(finder);
				}
			if (found==0) cout<<"A music with the artist name you provided doesn't exist";
		}
		else if(x==4)
		{
			int found=0, i=1;music *finder;
			cout<<"enter the genre of the Music you want to Search:\n>> ";char genreBuffer[40];cin>>genreBuffer;
			for(finder=start;finder->next!=NULL;finder=finder->next)
				{
				if(strcmp(finder->genre,genreBuffer)==0)
					{
					found=1;
					cout<<"Music "<<i<<":\n";dispFrmArg(finder);//for displaying
					i++;
					}
				}
				if(strcmp(finder->genre,genreBuffer)==0)
				{
				cout<<"Music "<<i<<":\n"; dispFrmArg(finder);
				}
			if (found==0) cout<<"A music with such genre doesn't exist";
		}
		else if(x==5)
		{
			int found=0, i=1;music *finder;
			cout<<"enter the time Duration of the Music you want to Search:\n>> "; float dura=floatValidator();
			for(finder=start;finder->next!=NULL;finder=finder->next)
				{
				if(finder->duration==dura)
					{
					found=1;
					cout<<"Music "<<i<<":\n";dispFrmArg(finder);//for displaying
					i++;
					}
				}
				if(finder->duration==dura)
				{
				cout<<"Music "<<i<<":\n"; dispFrmArg(finder);
				}
			if (found==0) cout<<"A music with such Such time duration doesn't exist";
		}
		else if(x==6)
		{
			int found=0, i=1;music *finder;
			cout<<"enter the year to search if any music was released in that year\n>> ";int yearRlsd=validator();
			for(finder=start;finder->next!=NULL;finder=finder->next)
				{
				if(finder->yearReleased==yearRlsd)
					{
					found=1;
					cout<<"Music "<<i<<":\n";dispFrmArg(finder);//for displaying
					i++;
					}
				}
				if(finder->yearReleased==yearRlsd)
				{
				cout<<"Music "<<i<<":\n"; dispFrmArg(finder);
				}
			if (found==0) cout<<"Cant find a music released in the year you provided.";
		}
}
}
void dispFrmArg(music *oneMusic){
				cout<<"--------------------------------------------------------------------------------------------------\n";
				cout<<"ID: "<<oneMusic->musicID<<", Title: "<<oneMusic->title<<", Artist: "<<oneMusic->artist<<", Duration: "<<oneMusic->duration;
				cout<<", Year Released: "<<oneMusic->yearReleased<<", genre: "<<oneMusic->genre<<endl;
				cout<<"=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=++==+=+=+\n\n";
}
/*
#########################################################
----------------functions for Question 14----------------
#########################################################
*/
void displayAll(){
	if (start==NULL)cout<<"\nlist is empty";
	else
	{
		int i=1;music *traverser=new music;
		for(traverser=start;traverser->next!=NULL;traverser=traverser->next){
		cout<<"Music "<<i<<":\n";
		cout<<"--------------------------------------------------------------------------------------------------\n";
		cout<<"ID: "<<traverser->musicID<<", Title: "<<traverser->title<<", Artist: "<<traverser->artist<<", Duration: "<<traverser->duration;
		cout<<", Year Released: "<<traverser->yearReleased<<", genre: "<<traverser->genre<<endl;
		cout<<"=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=++==+=+=+\n\n";
		i++;
		}
		cout<<"Music "<<i<<":\n";
		cout<<"--------------------------------------------------------------------------------------------------\n";
		cout<<"ID: "<<traverser->musicID<<", Title: "<<traverser->title<<", Artist: "<<traverser->artist<<", Duration: "<<traverser->duration;
		cout<<", Year Released: "<<traverser->yearReleased<<", genre: "<<traverser->genre<<endl;
		cout<<"=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=++==+=+=+\n\n";
}
}
/*
#########################################################
----------------functions for Question 15----------------
#########################################################
*/
void countNode(){
	if (start==NULL)cout<<"\n list is empty";
	else
	{
		int i=1;music *traverser;
		for(traverser=start;traverser->next!=NULL;traverser=traverser->next){
			i++;
		}
		cout<<i<<" number of music is found";
	}
}
/*
#########################################################
----------------functions for Question 16----------------
#########################################################
*/
void countOccur(){
	if (start==NULL)cout<<"\n list is empty";
	else{
		cout<<"The occurence of which attribute you want to know\n";
		cout<<"1. ID\n2. Title\n3. Artist\n4. genre\n5. Duration\n6. Year Released\n>>";
		int x=validator();
		if(x>6||x<1)while(x>6||x<1){
			cout<<"please enter onlly between 1 and 6\n>>";
			x=validator();
		}
		if(x==1){
			cout<<"enter the ID you want to count\n>>";
			char id[20];cin>>id;
			int i=0;music *traverser=new music;
			for(traverser=start;traverser->next!=NULL;traverser=traverser->next){
				if(strcmp(traverser->musicID,id)==0)
				i++;
				}
				if(strcmp(traverser->musicID,id)==0)
				i++;

		cout<<"total number of music with an ID "<<id<<" is: "<<i;
		}
		else if(x==2){
			cout<<"enter the Title you want to count\n>>";
			char title[40];cin>>title;
			int i=0;music *traverser=new music;
			for(traverser=start;traverser->next!=NULL;traverser=traverser->next){
				if(strcmp(traverser->title,title)==0)
				i++;
				}
				if(strcmp(traverser->title,title)==0)
				i++;
		cout<<"total number of music with a title "<<title<<" is: "<<i;
		}
		else if(x==3){
			cout<<"enter the name of the artist you want to count\n>>";
			char artist[30];cin>>artist;
			int i=0;music *traverser=new music;
			for(traverser=start;traverser->next!=NULL;traverser=traverser->next){
				if(strcmp(traverser->artist,artist)==0)
				i++;
				}
				if(strcmp(traverser->artist,artist)==0)
				i++;
		cout<<"total number of music with an artist name "<<artist<<" is: "<<i;
		}
		else if(x==4){
			cout<<"enter the genre of a music you want to count\n>>";
			char genre[40];cin>>genre;
			int i=0;music *traverser=new music;
			for(traverser=start;traverser->next!=NULL;traverser=traverser->next){
				if(strcmp(traverser->genre,genre)==0)
				i++;
				}
				if(strcmp(traverser->genre,genre)==0)
				i++;
			cout<<"total number of music with a genre "<<genre<<" is: "<<i;
		}
		else if(x==5){
			cout<<"enter the duration of a music you want to count\n>>";
			float duration=floatValidator();
			//validating the duration
			if(duration>20||duration<1)while(duration>20||duration<1){
				cout<<"duration cant be greater than 20 or less than 1. please enter a valid duration.\n>";
				duration=floatValidator();
			}
			int i=0;music *traverser=new music;
			for(traverser=start;traverser->next!=NULL;traverser=traverser->next){
				if(traverser->duration==duration)
				i++;
				}
				if(traverser->duration==duration)
				i++;
		cout<<"total number of music with a Duration of "<<duration<<" minutes is: "<<i;

		}
		else if(x==6){
			cout<<"enter the release year of a music you want to count\n>>";
			int yearReleased=validator();
			//validating the year released
			if(yearReleased>2022||yearReleased<1800)while(yearReleased>2022||yearReleased<1900){
				cout<<"The list doesn't have a music released either before 1800 or after 2022. please enter a valid year.\n>";
				yearReleased=validator();
			}
			int i=0;music *traverser=new music;
			for(traverser=start;traverser->next!=NULL;traverser=traverser->next){
				if(traverser->yearReleased==yearReleased)
				i++;
				}
				if(traverser->yearReleased==yearReleased)
				i++;
		cout<<"total number of musics which were released in "<<yearReleased<<" is: "<<i;
		}
}
}
/*
#########################################################
----------------functions for Question 17----------------
#########################################################
*/
void modifyByAttrib(){
	if (start==NULL)cout<<"\n list is empty";
	else{
		cout<<"by which attribute you want to modify the music\n";
		cout<<"1. By ID\n2. By Title\n3. By Artist\n4. By genre\n5. By Duration\n6. By Year Released\n>>";
		int x=floatValidator();
		if(x>6||x<1)while(x>6||x<1){
			cout<<"please enter onlly between 1 and 6\n";
			x=floatValidator();
		}
		music *finder=new music;
			if(x==1){
				cout<<"Enter the ID of the music you want to modify\n>>";char id[20];cin>>id;
				music *finder=new music;
				int idExist=0;
				//validating the id exists in the list
				for(finder=start;finder->next!=NULL;finder=finder->next){
					if(strcmp(finder->musicID,id)==0) idExist=1;
				}
				if(strcmp(finder->musicID,id)==0) idExist=1;
				if(idExist==0)while(idExist==0){
					cout<<"ID doesn't Exist in the list, Please try again with another one\n>>";
					cin>>id;
					for(finder=start;finder->next!=NULL;finder=finder->next){
					if(strcmp(finder->musicID,id)==0) idExist=1;
					}
					if(strcmp(finder->musicID,id)==0) idExist=1;
				}
				cout<<"\nID found. Now Enter the new ID for your music\n>>";char newId[20];cin>>newId;
				idExist=0;
				//validating if id doesn't exist in the list, since an id has to a unique
				for(finder=start;finder->next!=NULL;finder=finder->next){
					if(strcmp(finder->musicID,newId)==1) idExist=1;
				}
				if(strcmp(finder->musicID,newId)==0) idExist=1;
				if(idExist==1){
				while(idExist==1){
					idExist=0;
					cout<<"You cant enter an ID that is found in the list. Try a unique one\n>>";
					cin>>newId;
					for(finder=start;finder->next!=NULL;finder=finder->next){
					if(strcmp(finder->musicID,newId)==0) idExist=1;
					}
					if(strcmp(finder->musicID,newId)==0) idExist=1;
				}
				}
				//now inserting the two values obtained
				for(finder=start;finder->next!=NULL;finder=finder->next){
				if(strcmp(finder->musicID,id)==0){
					strcpy(finder->musicID,newId);
					cout<<"The Music with an ID "<<id<<" has been modified to "<<newId;
				}
					}
						if(strcmp(finder->musicID,id)==0){
					strcpy(finder->musicID,newId);
					cout<<"The Music with an ID "<<id<<" has been modified to "<<newId;
				}
			}
			else if(x==2){
			int titleExist=0;
			cout<<"enter the title of the music you want to modify\n>>";
			char title[40];
			cin>>title;
			//Cheking whether the title exists
			int Exist=0;
			for(finder=start;finder->next!=NULL;finder=finder->next){
					if(strcmp(finder->title,title)==0) Exist=1;
				}
				if(strcmp(finder->title,title)==0) Exist=1;
				if(Exist==0)while(Exist==0){
					cout<<"title doesn't exist in the list, Please try again with another one\n>>";
					cin>>title;
					for(finder=start;finder->next!=NULL;finder=finder->next){
					if(strcmp(finder->title,title)==0) Exist=1;
					}
					if(strcmp(finder->title,title)==0) Exist=1;
				}
			cout<<"\nTitle found. Now enter the new title\n>>";
			char newtitle[40];
			cin>>newtitle;
			for(finder=start;finder->next!=NULL;finder=finder->next){
				if(strcmp(finder->title,title)==0){
					strcpy(finder->title,newtitle);
					titleExist=1;
				}
			}
				if(strcmp(finder->title,title)==0){
					strcpy(finder->title,newtitle);
					titleExist=1;
				}
			if(titleExist==1)	cout<<"all music with the title "<<title<<" are modified to "<<newtitle;
			else cout<<"A music with the title "<<title<<" doesn't exist";
			}
			else if(x==3){
			int artistExist=0;
			cout<<"enter the artist of the music you want to modify\n>>";
			char artist[30];
			cin>>artist;
			//Cheking whether the title exists
			int Exist=0;
			for(finder=start;finder->next!=NULL;finder=finder->next){
					if(strcmp(finder->artist,artist)==0) Exist=1;
				}
				if(strcmp(finder->artist,artist)==0) Exist=1;
				if(Exist==0)while(Exist==0){
					cout<<"artist name doesn't exist in the list, Please try again with another one\n>>";
					cin>>artist;
					for(finder=start;finder->next!=NULL;finder=finder->next){
					if(strcmp(finder->artist,artist)==0) Exist=1;
					}
					if(strcmp(finder->artist,artist)==0) Exist=1;
				}
			cout<<"\nName found. Now enter the new name artist\n>>";
			char newartist[30];
			cin>>newartist;
			for(finder=start;finder->next!=NULL;finder=finder->next){
				if(strcmp(finder->artist,artist)==0){
					strcpy(finder->artist,newartist);
					artistExist=1;
				}
			}
				if(strcmp(finder->artist,artist)==0){
					strcpy(finder->artist,newartist);
					artistExist=1;
				}
			if(artistExist==1)	cout<<"all music with the title "<<artist<<" are modified to "<<newartist;
			else cout<<"A music with the artist "<<artist<<" doesn't exist";
			}
			else if(x==4){
			int genreExist=0;
			cout<<"enter the genre of the music you want to modify\n>>";
			char genre[40];
			cin>>genre;
			//Cheking whether the title exists
			int Exist=0;
			for(finder=start;finder->next!=NULL;finder=finder->next){
					if(strcmp(finder->genre,genre)==0) Exist=1;
				}
				if(strcmp(finder->genre,genre)==0) Exist=1;
				if(Exist==0)while(Exist==0){
					cout<<"genre doesn't exist in the list, Please try again with another one\n>>";
					cin>>genre;
					for(finder=start;finder->next!=NULL;finder=finder->next){
					if(strcmp(finder->genre,genre)==0) Exist=1;
					}
					if(strcmp(finder->genre,genre)==0) Exist=1;
				}
			cout<<"\ngenre found. Now enter the new genre\n>>";
			char newgenre[40];
			cin>>newgenre;
			for(finder=start;finder->next!=NULL;finder=finder->next){
				if(strcmp(finder->genre,genre)==0){
					strcpy(finder->genre,newgenre);
					genreExist=1;
				}
			}
				if(strcmp(finder->genre,genre)==0){
					strcpy(finder->genre,newgenre);
					genreExist=1;
				}
			if(genreExist==1)	cout<<"all music with the genre "<<genre<<" are modified to "<<newgenre;
			else cout<<"A music with the genre "<<genre<<" doesn't exist";
			}
			else if(x==5){
			int durationExist=0;
			cout<<"enter the duration of the music you want to modify. Format=min.sec(eg 3.41)\n>>";
			float duration=floatValidator();
			//checking whether duration exits
			int Exist=0;
			for(finder=start;finder->next!=NULL;finder=finder->next){
					if(finder->duration==duration) Exist=1;
				}
					if(finder->duration==duration) Exist=1;
					if(Exist==0)while(Exist==0){
					cout<<"A music with such duration doesn't exist in the list, Please try again with another one\n>>";
					cin>>duration;
					for(finder=start;finder->next!=NULL;finder=finder->next){
					if(finder->duration==duration) Exist=1;
					}
					if(finder->duration==duration) Exist=1;
				}
			cout<<"Now enter the new duration\n>>";
			float newduration=floatValidator();
			for(finder=start;finder->next!=NULL;finder=finder->next){
				if(finder->duration==duration){
					finder->duration=newduration;
					durationExist=1;
				}
			}
				if(finder->duration==duration){
					finder->duration=newduration;
					durationExist=1;
				}
			if(durationExist==1)	cout<<"all music with the duration "<<duration<<" are modified to "<<newduration;
			else cout<<"A music with the duration "<<duration<<" doesn't exist";
			}
			else if(x==6){
			int yearExist=0;
			cout<<"enter the year released of the music you want to modify.\n>>";
			int yearReleased=validator();
				//checking whether duration exits
			int Exist=0;
			for(finder=start;finder->next!=NULL;finder=finder->next){
					if(finder->yearReleased==yearReleased) Exist=1;
				}
					if(finder->yearReleased==yearReleased) Exist=1;
					if(Exist==0)while(Exist==0){
					cout<<" There is no music that was release in "<<yearReleased<<", Please try again with another one\n>>";
					yearReleased=validator();
					for(finder=start;finder->next!=NULL;finder=finder->next){
					if(finder->yearReleased==yearReleased) Exist=1;
					}
					if(finder->yearReleased==yearReleased) Exist=1;
				}
			cout<<"Now enter the new year released\n>>";
			int newyearReleased=validator();
			for(finder=start;finder->next!=NULL;finder=finder->next){
				if(finder->yearReleased==yearReleased){
					finder->duration=newyearReleased;
					yearExist=1;
				}
			}
				if(finder->yearReleased==yearReleased){
					finder->duration=newyearReleased;
					yearExist=1;
				}
			if(yearExist==1)	cout<<"all musics that were released in "<<yearReleased<<" are modified to "<<newyearReleased;
			else cout<<"A music with the year released "<<yearReleased<<" doesn't exist";
			}
	}
}
/*
#########################################################
----------------functions for Question 18----------------
#########################################################
*/
void sortByAttrib(){
	if(start==NULL) cout<<"list is empty add some musics first";
	else if(start->next==NULL)cout<<"There is only one Music in the list. Nothing to sort";
	else{
		cout<<"By which attribute do you want to sort your data";
		cout<<"\n1. By ID \n2. By Title\n3. By Artist Name\n4. By Gerere \n5. By Duration \n6. By release year\n>>";
		int x=validator();
		if(x==1){
			cout<<"Ascending or Descending order?\n1. Ascending\n2. Descending\n>>";
			int y=validator();
			if(y!=1&&y!=2)while(y!=2&&y!=1){cout<<"please enter the right order\n>>"; y=validator();			}
			char id[20]="musicID";
			if(y==1){charSorter(id,y);cout<<"Music items sorted successfully based on their ID in ascending order";}
			else if(y==2){charSorter(id,y);cout<<"Music items sorted successfully based on their ID in Descending order";}
		}
		else if(x==2){
			cout<<"Ascending or Descending order?\n1. Ascending\n2. Descending\n>>";
			int y=validator();
			if(y!=1&&y!=2)while(y!=2&&y!=1){cout<<"please enter the right order\n>>"; y=validator();			}
			char title[20]="title";
			if(y==1){charSorter(title,1);cout<<"Music items sorted successfully based on their Title Alphabet in ascending order";}
			else if(y==2){charSorter(title,2);cout<<"Music items sorted successfully based on their Title Alphabet in Descending order";}
		}
		else if(x==3){
			cout<<"Ascending or Descending order?\n1. Ascending\n2. Descending\n>>";
			int y=validator();
			if(y!=1&&y!=2)while(y!=2&&y!=1){cout<<"please enter the right order\n>>"; y=validator();			}
			char artist[20]="artist";
			if(y==1){charSorter(artist,1);cout<<"Music items sorted successfully based on Alphabet of their artist names in ascending order";}
			else if(y==2){charSorter(artist,2);cout<<"Music items sorted successfully based on Alphabet of their artist names in Descending order";}
		}
		else if(x==4){
			cout<<"Ascending or Descending order?\n1. Assending\n2. Descending\n>>";
			int y=validator();
			if(y!=1&&y!=2)while(y!=2&&y!=1){cout<<"please enter the right order\n>>"; y=validator();			}
			char genre[20]="genre";
			if(y==1){charSorter(genre,1);cout<<"Music items sorted successfully based on their genre Category in ascending order";}
			else if(y==2){charSorter(genre,2);cout<<"Music items sorted successfully based on their genre Category in Descending order";}
		}// 1-4, they are all calling one function, but below(5 and 6), both of them are different data types(int and float) so they are calling different funcitions
		else if(x==5){
			cout<<"Ascending or Descending order?\n1. Assending\n2. Descending\n>>";
			int y=validator();
			if(y!=1&&y!=2)while(y!=2&&y!=1){cout<<"please enter the right order\n>>"; y=validator();			}
			if(y==1){durSorter(1);cout<<"Music items sorted successfully based on their Duration in Ascending order";}
			else if(y==2){durSorter(2);cout<<"Music items sorted successfully based on their Duration in Descending order";}
		}

		else if(x==6){
			cout<<"Ascending or Descending order?\n1. Assending\n2. Descending\n>>";
			int y=validator();
			if(y!=1&&y!=2)while(y!=2&&y!=1){cout<<"please enter the right order\n>>"; y=validator();			}
			if(y==1){yearSorter(1);cout<<"Music items sorted successfully based on their release year in Ascending order";}
			else if(y==2){yearSorter(2);cout<<"Music items sorted successfully based on their release year in Descending order";}
		}
	}
}
//*************************************************Actual sorter functions ID, Title, Artist, and genre
void charSorter(char text[], int order){
//*******************************//Algoithm used for sorting -- selection sort
	if (order==1){
		music *traverser=new music;
		music *comparePoint=new music;
		music *min=new music;
		for(comparePoint=start;comparePoint->next!=NULL;comparePoint=comparePoint->next){
			min=comparePoint;
			//Inner loop for ID
			if(strcmp(text,"musicID")==0){
				for(traverser=comparePoint;traverser->next!=NULL;traverser=traverser->next){
				if(strcmpi(min->musicID,traverser->musicID)>0) min=traverser;
				}
				if(strcmpi(min->musicID,traverser->musicID)>0) min=traverser;
				}
			//Inner loop for title
			if(strcmp(text,"title")==0){
				for(traverser=comparePoint;traverser->next!=NULL;traverser=traverser->next){
				if(strcmpi(min->title,traverser->title)>0) min=traverser;
				}
				if(strcmpi(min->title,traverser->title)>0) min=traverser;
				}
			//Inner loop for artist
			if(strcmp(text,"artist")==0){
				for(traverser=comparePoint;traverser->next!=NULL;traverser=traverser->next){
				if(strcmpi(min->artist,traverser->artist)>0) min=traverser;
				}
				if(strcmpi(min->artist,traverser->artist)>0) min=traverser;
				}
			//Inner loop for genre
			if(strcmp(text,"genre")==0){
				for(traverser=comparePoint;traverser->next!=NULL;traverser=traverser->next){
				if(strcmpi(min->genre,traverser->genre)>0) min=traverser;
				}
				if(strcmpi(min->genre,traverser->genre)>0) min=traverser;
				}
			//swap
			if(strcmp(min->musicID,comparePoint->musicID)!=0){
				//swapping
				music *temp=new music;
				strcpy(temp->musicID,min->musicID);
				strcpy(temp->title,min->title);
				strcpy(temp->artist,min->artist);
				strcpy(temp->genre,min->genre);
				temp->duration=min->duration;
				temp->yearReleased=min->yearReleased;//copy to temp complete
				strcpy(min->musicID,comparePoint->musicID);
				strcpy(min->title,comparePoint->title);
				strcpy(min->artist,comparePoint->artist);
				strcpy(min->genre,comparePoint->genre);
				min->duration=comparePoint->duration;
				min->yearReleased=comparePoint->yearReleased;//copy to temp complete
				strcpy(comparePoint->musicID,temp->musicID);
				strcpy(comparePoint->title,temp->title);
				strcpy(comparePoint->artist,temp->artist);
				strcpy(comparePoint->genre,temp->genre);
				comparePoint->duration=temp->duration;
				comparePoint->yearReleased=temp->yearReleased;//copy to comparePoint complete
				//swapping complete
				delete temp;
			}
			}
		}
	if (order==2){
		music *traverser=new music;
		music *comparePoint=new music;
		music *min=new music;
		for(comparePoint=start;comparePoint->next!=NULL;comparePoint=comparePoint->next){
			min=comparePoint;
			//loop for id
			if(strcmp(text,"musicID")==0){

			for(traverser=comparePoint;traverser->next!=NULL;traverser=traverser->next){
				if(strcmpi(min->musicID,traverser->musicID)<0) min=traverser;
			}
			if(strcmpi(min->musicID,traverser->musicID)<0) min=traverser;
				}
			if(strcmp(text,"title")==0){

			for(traverser=comparePoint;traverser->next!=NULL;traverser=traverser->next){
				if(strcmpi(min->title,traverser->title)<0) min=traverser;
			}
			if(strcmpi(min->title,traverser->title)<0) min=traverser;
				}
				if(strcmp(text,"artist")==0){

			for(traverser=comparePoint;traverser->next!=NULL;traverser=traverser->next){
				if(strcmpi(min->artist,traverser->artist)<0) min=traverser;
			}
			if(strcmpi(min->artist,traverser->artist)<0) min=traverser;
				}
				if(strcmp(text,"genre")==0){

			for(traverser=comparePoint;traverser->next!=NULL;traverser=traverser->next){
				if(strcmpi(min->genre,traverser->genre)<0) min=traverser;
			}
			if(strcmpi(min->genre,traverser->genre)<0) min=traverser;
				}
			//swap
			if(strcmp(min->musicID,comparePoint->musicID)!=0){
				//swapping
				music *temp=new music;
				strcpy(temp->musicID,min->musicID);
				strcpy(temp->title,min->title);
				strcpy(temp->artist,min->artist);
				strcpy(temp->genre,min->genre);
				temp->duration=min->duration;
				temp->yearReleased=min->yearReleased;//copy to temp complete
				strcpy(min->musicID,comparePoint->musicID);
				strcpy(min->title,comparePoint->title);
				strcpy(min->artist,comparePoint->artist);
				strcpy(min->genre,comparePoint->genre);
				min->duration=comparePoint->duration;
				min->yearReleased=comparePoint->yearReleased;//copy to temp complete
				strcpy(comparePoint->musicID,temp->musicID);
				strcpy(comparePoint->title,temp->title);
				strcpy(comparePoint->artist,temp->artist);
				strcpy(comparePoint->genre,temp->genre);
				comparePoint->duration=temp->duration;
				comparePoint->yearReleased=temp->yearReleased;//copy to comparePoint complete
				//swapping complete
				delete temp;
			}
			}
	}
}
//----*************************************************************------------------------------------------
void durSorter(int order){
	music *comparePoint=new music;
	music *traverser=new music;
	if (order==1){
		music *min=new music;
		for(comparePoint=start;comparePoint->next!=NULL;comparePoint=comparePoint->next){
			min=comparePoint;

			for(traverser=comparePoint;traverser->next!=NULL;traverser=traverser->next){
				if(min->duration > traverser->duration) min=traverser;
			}
			if(min->duration > traverser->duration) min=traverser;
			if(strcmp(min->musicID,comparePoint->musicID)!=0){
				//swapping
				music *temp=new music;
				strcpy(temp->musicID,min->musicID);
				strcpy(temp->title,min->title);
				strcpy(temp->artist,min->artist);
				strcpy(temp->genre,min->genre);
				temp->duration=min->duration;
				temp->yearReleased=min->yearReleased;//copy to temp complete
				strcpy(min->musicID,comparePoint->musicID);
				strcpy(min->title,comparePoint->title);
				strcpy(min->artist,comparePoint->artist);
				strcpy(min->genre,comparePoint->genre);
				min->duration=comparePoint->duration;
				min->yearReleased=comparePoint->yearReleased;//copy to temp complete
				strcpy(comparePoint->musicID,temp->musicID);
				strcpy(comparePoint->title,temp->title);
				strcpy(comparePoint->artist,temp->artist);
				strcpy(comparePoint->genre,temp->genre);
				comparePoint->duration=temp->duration;
				comparePoint->yearReleased=temp->yearReleased;//copy to comparePoint complete
				//swapping complete
				delete temp;
			}
			}
		}
	else if(order==2){
		music *max=new music;
		for(comparePoint=start;comparePoint->next!=NULL;comparePoint=comparePoint->next){
			max=comparePoint;

			for(traverser=comparePoint;traverser->next!=NULL;traverser=traverser->next){
				if(max->duration < traverser->duration) max=traverser;
			}
			if(max->duration < traverser->duration) max=traverser;
			if(strcmp(max->musicID,comparePoint->musicID)!=0){
				//swapping
				music *temp=new music;
				strcpy(temp->musicID,max->musicID);
				strcpy(temp->title,max->title);
				strcpy(temp->artist,max->artist);
				strcpy(temp->genre,max->genre);
				temp->duration=max->duration;
				temp->yearReleased=max->yearReleased;//copy to temp complete
				strcpy(max->musicID,comparePoint->musicID);
				strcpy(max->title,comparePoint->title);
				strcpy(max->artist,comparePoint->artist);
				strcpy(max->genre,comparePoint->genre);
				max->duration=comparePoint->duration;
				max->yearReleased=comparePoint->yearReleased;//copy to temp complete
				strcpy(comparePoint->musicID,temp->musicID);
				strcpy(comparePoint->title,temp->title);
				strcpy(comparePoint->artist,temp->artist);
				strcpy(comparePoint->genre,temp->genre);
				comparePoint->duration=temp->duration;
				comparePoint->yearReleased=temp->yearReleased;//copy to comparePoint complete
				//swapping complete
				delete temp;
			}
			}
		}
}

//-***********************************************************---------------------------------------------
void yearSorter(int order){
	music *comparePoint=new music;
	music *traverser=new music;
	if (order==1){
		music *min=new music;
		for(comparePoint=start;comparePoint->next!=NULL;comparePoint=comparePoint->next){
			min=comparePoint;

			for(traverser=comparePoint;traverser->next!=NULL;traverser=traverser->next){
				if(min->yearReleased > traverser->yearReleased) min=traverser;
			}
			if(min->yearReleased > traverser->yearReleased) min=traverser;
			if(strcmp(min->musicID,comparePoint->musicID)!=0){//we used id to check if min has changed, since ID is unique in the whole program
				//swapping
				music *temp=new music;
				strcpy(temp->musicID,min->musicID);
				strcpy(temp->title,min->title);
				strcpy(temp->artist,min->artist);
				strcpy(temp->genre,min->genre);
				temp->duration=min->duration;
				temp->yearReleased=min->yearReleased;//copy to temp complete
				strcpy(min->musicID,comparePoint->musicID);
				strcpy(min->title,comparePoint->title);
				strcpy(min->artist,comparePoint->artist);
				strcpy(min->genre,comparePoint->genre);
				min->duration=comparePoint->duration;
				min->yearReleased=comparePoint->yearReleased;//copy to temp complete
				strcpy(comparePoint->musicID,temp->musicID);
				strcpy(comparePoint->title,temp->title);
				strcpy(comparePoint->artist,temp->artist);
				strcpy(comparePoint->genre,temp->genre);
				comparePoint->duration=temp->duration;
				comparePoint->yearReleased=temp->yearReleased;//copy to comparePoint complete
				//swapping complete
				delete temp;
			}
			}
		}
	else if(order==2){
		music *max=new music;
		for(comparePoint=start;comparePoint->next!=NULL;comparePoint=comparePoint->next){
			max=comparePoint;

			for(traverser=comparePoint;traverser->next!=NULL;traverser=traverser->next){
				if(max->yearReleased < traverser->yearReleased) max=traverser;
			}
			if(max->yearReleased < traverser->yearReleased) max=traverser;
			if(strcmp(max->musicID,comparePoint->musicID)!=0){
				//swapping
				music *temp=new music;
				strcpy(temp->musicID,max->musicID);
				strcpy(temp->title,max->title);
				strcpy(temp->artist,max->artist);
				strcpy(temp->genre,max->genre);
				temp->duration=max->duration;
				temp->yearReleased=max->yearReleased;//copy to temp complete
				strcpy(max->musicID,comparePoint->musicID);
				strcpy(max->title,comparePoint->title);
				strcpy(max->artist,comparePoint->artist);
				strcpy(max->genre,comparePoint->genre);
				max->duration=comparePoint->duration;
				max->yearReleased=comparePoint->yearReleased;//copy to temp complete
				strcpy(comparePoint->musicID,temp->musicID);
				strcpy(comparePoint->title,temp->title);
				strcpy(comparePoint->artist,temp->artist);
				strcpy(comparePoint->genre,temp->genre);
				comparePoint->duration=temp->duration;
				comparePoint->yearReleased=temp->yearReleased;//copy to comparePoint complete
				//swapping complete
				delete temp;
			}
			}
		}
}
/*
#########################################################
----------------functions for Question 19----------------
#########################################################
*/
void dispTop(){
	if(start==NULL){
		cout<<"The list is empty. Add some items first";
	}
	else if(start->next==NULL){
		cout<<"There is only one music in the list. Enter 1 if you want see it other wise press except other key.\n>>";
		int x=validator();
		if (x==1){
			displayAll();
		}
		else {
			cout<<"getting you back to the main menu...";
		}
	}
	else{
		cout<<"Select the criteria for which you want to see top students?";
		cout<<"\n1. ID number\n2. Title Alphabet Order\n3. Artist's name Alphabet order\n4. genre order\n5. Duration order\n6. Release year Order\n>>";
		int x=validator();
		if(x==1){
			char text[]="musicID";
			cout<<"Top ID by which order?\n1. Ascending\n2. Descending\n>>";
			int x=validator();
			if(x!=1&&x!=2)while(x!=1&&x!=2){cout<<"please enter 1 or 2\n>>";x=validator();			}
			cout<<"how many top musics do you want?\n>>Top: ";
			int y=validator();
			int node=nodeCounterForTop();
			if(y<=node){
				music *traverser=new music;
				charSorter(text,x);
				traverser=start;
				for(int i=1;i<=y;i++,traverser=traverser->next){
					cout<<"Music "<<i;
					dispFrmArg(traverser);
				}
			}
			else{
				cout<<"No such amount of musics in the list. Do you still want to see the available ones?";
				cout<<"\n1. Yes\n2. No";
				int z=validator();
				if(z==1){
					charSorter(text,x);
					cout<<"All the Musics ordered with title alphabet order";
					displayAll();
				}
			}
		}
		else if(x==2){
			char text[]="title";
			cout<<"Top musics by which order?\n1. Ascending\n2. Descending\n>>";
			int x=validator();
			if(x!=1&&x!=2)while(x!=1&&x!=2){cout<<"please enter 1 or 2\n>>";x=validator();			}
			cout<<"how many top musics do you want?\n>>Top: ";
			int y=validator();
			int node=nodeCounterForTop();
			if(y<=node){
				music *traverser=new music;
				charSorter(text,x);
				traverser=start;
				for(int i=1;i<=y;i++){
					cout<<"Music "<<i;
					dispFrmArg(traverser);
					traverser=traverser->next;
				}
			}
			else{
				cout<<"No such amount of musics in the list. Do you still want to see the available ones?";
				cout<<"\n1. Yes\n2. No";
				int z=validator();
				if(z==1){
					charSorter(text,x);
					cout<<"All the Musics ordered with title alphabet order";
					displayAll();
				}
			}
		}
		else if(x==3){
			char text[]="artist";
			cout<<"Top musics by which order?\n1. Ascending\n2. Descending\n>>";
			int x=validator();
			if(x!=1&&x!=2)while(x!=1&&x!=2){cout<<"please enter 1 or 2\n>>";x=validator();			}
			cout<<"how many top musics do you want?\n>>Top: ";
			int y=validator();
			int node=nodeCounterForTop();
			if(y<=node){
				music *traverser=new music;
				charSorter(text,x);
				traverser=start;
				for(int i=1;i<=y;i++){
					cout<<"Music "<<i;
					dispFrmArg(traverser);
					traverser=traverser->next;
				}
			}
			else{
				cout<<"No such amount of musics in the list. Do you still want to see the available ones?";
				cout<<"\n1. Yes\n2. No";
				int z=validator();
				if(z==1){
					charSorter(text,x);
					cout<<"All the Musics ordered with artist name alphabet";
					displayAll();
				}
			}
		}
		else if(x==4){
			char text[]="genre";
			cout<<"Top musics by which order?\n1. Ascending\n2. Descending\n>>";
			int x=validator();
			if(x!=1&&x!=2)while(x!=1&&x!=2){cout<<"please enter 1 or 2\n>>";x=validator();		}
			cout<<"how many top musics do you want?\n>>Top: ";
			int y=validator();
			int node=nodeCounterForTop();
			if(y<=node){
				music *traverser=new music;
				charSorter(text,x);
				traverser=start;
				for(int i=1;i<=y;i++){
					cout<<"Music "<<i;
					dispFrmArg(traverser);
					traverser=traverser->next;
				}
			}
			else{
				cout<<"No such amount of musics in the list. Do you still want to see the available ones?";
				cout<<"\n1. Yes\n2. No";
				int z=validator();
				if(z==1){
					charSorter(text,x);
					cout<<"All the Musics ordered with genre alphabet";
					displayAll();
				}
			}
		}
		else if(x==5){
			cout<<"By which order do you want to see the top musics?\n1. Ascending\n2. Descending\n>>";
			int x=validator();
			if(x!=1&&x!=2)while(x!=1&&x!=2){cout<<"please enter 1 or 2\n>>";x=validator();			}
			cout<<"how many top musics do you want?\n>>Top: ";
			int y=validator();
			int node=nodeCounterForTop();
			if(y<=node){
				music *traverser=new music;
				durSorter(x);
				traverser=start;
				for(int i=1;i<=y;i++){
					cout<<"Music "<<i;
					dispFrmArg(traverser);
					traverser=traverser->next;
				}
			}
			else{
				cout<<"No such amount of musics in the list. Do you still want to see the available ones?";
				cout<<"\n1. Yes\n2. No";
				int z=validator();
				if(z==1){
					durSorter(x);
					cout<<"All the Musics ordered with their duration";
					displayAll();
				}
			}
		}
		else if(x==6){
			cout<<"By which order do you want to see the top musics?\n1. Ascending\n2. Descending\n>>";
			int x=validator();
			if(x!=1&&x!=2)while(x!=1&&x!=2){cout<<"please enter 1 or 2\n>>";x=validator();			}
			cout<<"how many top musics do you want?\n>>Top: ";
			int y=validator();
			int node=nodeCounterForTop();
			if(y<=node){
				music *traverser=new music;
				yearSorter(x);
				traverser=start;
				for(int i=1;i<=y;i++){
					cout<<"Music "<<i;
					dispFrmArg(traverser);
					traverser=traverser->next;
				}
			}
			else{
				cout<<"No such amount of musics in the list. Do you still want to see the available ones?";
				cout<<"\n1. Yes\n2. No";
				int z=validator();
				if(z==1){
					yearSorter(x);
					cout<<"All the Musics ordered with the year the got released";
					displayAll();
				}
			}
		}
	}
}
int nodeCounterForTop(){
		int i=1;music *traverser=new music;
		for(traverser=start;traverser->next!=NULL;traverser=traverser->next){
			i++;
		}
		return i;
}
/*
##############################################################################################
----------------Another additional functions are Definded before main function----------------
##############################################################################################
*/
/*
###############################################################################################
###############################################################################################
	   ############ #		# ##########		##########	   	 #           # #######		###
			#		#		# #					#			    # #	        #  #      #		###
			#		#		# #					#			   #   #       #   #       #	###
			#		######### ##########		##########    #     #     #    #       #	###
			#		#		# #					#			 #       #   #     #       #	###
			#		#		# #					#			#         # #      #      #		###
			#		#		# ##########		########## #           #       #######		###
###############################################################################################
###############################################################################################
*/
