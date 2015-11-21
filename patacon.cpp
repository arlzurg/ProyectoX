#include <bits/stdc++.h>
#include <conio.h>
#include <windows.h>
#include <fstream>
#include <iomanip>
using namespace std;
void gotoxy(int x,int y){
       HANDLE hcon;  
       hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
       COORD dwPos;  
       dwPos.X = x;  
       dwPos.Y= y;  
       SetConsoleCursorPosition(hcon,dwPos);  
}
void cargando(){
  	int cont=0;
  	gotoxy(38,22);cout<<"CARGANDO";
  	while(cont<2){
  		for(int i=47;i<=58;i++){
  			gotoxy(i,22);cout<<". ";
  			Sleep(50);
  			i++;
  			if(i==58) gotoxy(47,22);cout<<"\t"<<"\t"<<"\t";
  		}
  		cont++;
  	}
  	gotoxy(38,22);cout<<"\t"<<"\t"<<"\t";
  }
void marco(){
	 	for(int j=1;j<110;j++){
 			gotoxy(j,0);
 			cout<<char(205);
 			gotoxy(j,27);
 			cout<<char(205);
 	}
 	gotoxy(110,0);cout<<char(187);
 	gotoxy(1,0);cout<<char(201);
 	gotoxy(1,27);cout<<char(200);
 	gotoxy(110,27);cout<<char(188);
	gotoxy(2,26);cout<<"Version 0.03";  	
 	for(int k=0;k<26;k++){
 			gotoxy(1,k);
 			cout<<endl;
 			gotoxy(1,k+1);
 			cout<<char(186);
 			gotoxy(110,k+1);
 			cout<<char(186);
 	}
 	gotoxy(48,24);cout<<"PROYECTO X";
}
struct tipocambio{
	float sol;
	float dolar;
	float euro;
	float libra;

};

struct app{
	string nom;
	string desar;
	string anyo;
	float precio,tam,puntaje;
};
struct cuenta{ //añadi float saldo, dos apps
	string nombre;
	string apell;
	string usua;
	string contra;
	string pin;
	string correo;
	string cod;
	int verificador;
	float saldo;
	app aplic[5];
	app myaplic[5];
};
cuenta usu[100];
void ingreso(cuenta []);
void tienda(cuenta [],int);
void menutienda(cuenta [], int &, int ,int, app []);
void tusaplicaciones(cuenta [], int , int ,int, app []);
void compraraplicaciones(cuenta [], int &, int ,int, int, app []);
void carrito(cuenta [], int &, int &,int , app [] , int);
void tusaldo(cuenta [], int , int ,int , int , app  []);
void MenuAplicacion(cuenta [], int &, int , int ,int, app []);
void crear(cuenta [],int &);
char menuprinc();
char menuusu(int );
void mainusuario(int );
char mainadmin(int );
void menuadmin(int );
void PERFIL(cuenta usu[],int ind);
void MODIFICANDOPERFIL(cuenta usu[],int ind,char num);
void OPCIONESPERFILMODIFICABLES(cuenta usu[],int ind);
void VERIFICANDOCUENTA(cuenta usu[],int ind);
char MenuCambioA();
void menucambio(tipocambio);
int convertidor();

//alejandro
int usuCont;
void LeerArcheage();
void EscribirArcheage(cuenta);
void SobreEscribir(cuenta,ofstream &);
void ActualizarVerga();
int aggtmr=4; //esta cosa es igual a los usuarios de la linea 109 a 112

	
int main(){
	usu[0]={"Franco","Mecca","francosmp","francosmp","9876","stha-182@hotmail.com","leonardo",0, 20.0};
	usu[1]={"Hector","Huapaya","hackerman","bitcoins","1234","hecdan89@hotmail.com","crack",0, 20.0};
	usu[2]={"Isaac","Gamarra","aisac","sation123","g2e","manuply77@gmail.com","adhac",0, 20.0};
	usu[3]={"a","a","a","a","a","a","a",0, 20.0};
	int v=1;
	usuCont=0+aggtmr;
	//ifstream wew("cuentas.txt");
	LeerArcheage();
	/*
	bool seguir = true;
   	int n = usuCont;
   	char letra;
   	char a1[30];
   	char a2[30];
   	char a3[30];
   	char a4[30];
   	char a5[30];
   	char a6[30];
   	char a7[30];
   	
   	while(seguir){
     	wew.getline(a1,30,'*');
   	 	wew.getline(a2,30,'*');
	 	wew.getline(a3,30,'*');
	 	wew.getline(a4,30,'*');
	 	wew.getline(a5,30,'*');
	 	wew.getline(a6,30,'*');
	 	wew.getline(a7,30,'*');
	 	usu[n].nombre=a1;
	 	usu[n].apell=a2;
	 	usu[n].usua=a3;
	 	usu[n].contra=a4;
	 	usu[n].pin=a5;
	 	usu[n].correo=a6;
	 	usu[n].cod=a7;
	 	
   	 	n=n+1;
   	 	usuCont=n;
   	 	seguir=wew.get(letra);
   	};
	*/
	char o;
	while(v==1){
	marco();	
	o=menuprinc();
		switch(o){
			case '1': ingreso(usu); break;
			case '2': crear(usu,usuCont); break;
			case '3': v=0; break;		
		}
	}
}
char menuprinc(){
	int t=0;
	char a;
	string respo="";
	while(t==0){
	system("cls");
	marco();
	gotoxy(36,3);cout<<"-.-.-.-.-.-.BIENVENIDOS-.-.-.-.-.-"<<endl;
	gotoxy(36,8);cout<<"[1] INGRESAR"<<endl;
	gotoxy(36,13);cout<<"[2] CREAR USUARIO"<<endl;
	gotoxy(36,18);cout<<"[3] SALIR"<<endl;
	gotoxy(57,24);a=getch();
		t=1;
		if(a=='3'){
		gotoxy(57,18);cout<<"Deseas cerrar el Programa?(si/no)";
		while(respo=="")gotoxy(91,18),getline(cin,respo);
		while(respo!="si" && respo!="no"){
			gotoxy(85,18);cout<<"\t\t";
			respo="";
			while(respo=="")gotoxy(85,18),getline(cin,respo);
		}
			if(respo=="no") t=0;
			if(respo=="si")	t=1;
		}
	}
	system("cls");
	return a;
}
void ingreso(cuenta usu[]){
	string u="",p="",n="";
	char resp;
	int i,t=0,ind;
	system("cls");
	marco();
	gotoxy(38,2);cout<<"INGRESANDO"<<endl;
	gotoxy(38,4);cout<<"USUARIO: ";
	for(int i=38;i<67;i++){
 		gotoxy(i,6);cout<<char(205);
 		gotoxy(i,8);cout<<char(205);
 	}
 	gotoxy(37,7);cout<<char(186);
 	gotoxy(67,7);cout<<char(186);
 	gotoxy(67,6);cout<<char(187);
 	gotoxy(67,8);cout<<char(188);
 	gotoxy(37,6);cout<<char(201);
 	gotoxy(37,8);cout<<char(200);
	
	gotoxy(38,10);cout<<"CONTRASE"<<char(165)<<"A: ";
	for(int i=38;i<67;i++){
 		gotoxy(i,12);cout<<char(205);
 		gotoxy(i,14);cout<<char(205);
 	}
 	gotoxy(37,13);cout<<char(186);
 	gotoxy(67,13);cout<<char(186);
 	gotoxy(67,12);cout<<char(187);
 	gotoxy(67,14);cout<<char(188);
 	gotoxy(37,12);cout<<char(201);
 	gotoxy(37,14);cout<<char(200); 	
	gotoxy(38,16);cout<<"PIN: ";
	for(int i=38;i<67;i++){
 	gotoxy(i,18);cout<<char(205);
 	gotoxy(i,20);cout<<char(205);
 	}
 	gotoxy(37,19);cout<<char(186);
 	gotoxy(67,19);cout<<char(186);
 	gotoxy(67,18);cout<<char(187);
 	gotoxy(67,20);cout<<char(188);
 	gotoxy(37,18);cout<<char(201);
 	gotoxy(37,20);cout<<char(200);
 	
	while(u=="")gotoxy(39,7),getline(cin,u);
	while(p=="")gotoxy(39,13),getline(cin,p);
	while(n=="")gotoxy(39,19),getline(cin,n);
	for(i=0;i<100;i++){
		if(u==usu[i].usua && usu[i].verificador>=3){
			system("cls");
			ind=i;
			cout<<"Cuenta Bloqueada"<<endl;
			cout<<"Sera redirigido para recuperar su cuenta"<<endl;
			Sleep(3000);
			VERIFICANDOCUENTA(usu,ind);			
		}
		else{
			if(u==usu[i].usua && p==usu[i].contra && n==usu[i].pin && n!="g2e"){
				cargando();
				gotoxy(26,7);cout<<"(Valido)";
				gotoxy(26,13);cout<<"(Valido)";
				gotoxy(26,19);cout<<"(Valido)";
				Sleep(400);
				system("cls");
				t=1;
				ind=i;
				mainusuario(ind);
			}
			if(u==usu[i].usua && p==usu[i].contra && n=="g2e"){
				cargando();
				gotoxy(26,7);cout<<"(Valido)";
				gotoxy(26,13);cout<<"(Valido)";
				gotoxy(26,19);cout<<"(Valido)";
				Sleep(400);
				system("cls");
				t=1;
				ind=i;
				menuadmin(ind);
			}
			if(u==usu[i].usua && (p!=usu[i].contra or n!=usu[i].pin))
				usu[i].verificador++;
		}
	}
	while(t==0){
				cargando();
				gotoxy(24,7);cout<<"(Invalido)";
				gotoxy(24,13);cout<<"(Invalido)";
				gotoxy(24,19);cout<<"(Invalido)";
				Sleep(400);
				system("cls");
		marco();		
		gotoxy(37,5);cout<<"Usuario erroneo/no existe!"<<endl;
		gotoxy(37,10);cout<<"[1] Desea volver a intentar?"<<endl;
		gotoxy(37,15);cout<<"[2] Volver al menu principal"<<endl;
		gotoxy(57,24);resp=getch();
		system("cls");
		if(resp=='1'){
			ingreso(usu);
		}
		else{
			t=1;
		}
	}
}
void mainusuario(int ind){
	char o;
	int v=1;
	while(v==1){
	o=menuusu(ind);
		switch(o){
			case '1': PERFIL(usu,ind); break;
			case '2': tienda(usu,ind); break;
			case '3': v=0; break;		
		}
	}
}
char menuusu(int ind){
	int t=0;
	char a,x,y,z;
	string respo="";
	while(t==0){
	system("cls");
	marco();
	gotoxy(35,3);cout<<"-.-.-.-.-.-.BIENVENIDO, "<<usu[ind].nombre<<".-.-.-.-.-.-"<<endl;
	gotoxy(35,8);cout<<"[1] Perfil"<<endl;
	gotoxy(35,13);cout<<"[2] Tienda"<<endl;
	gotoxy(35,18);cout<<"[3] Cerrar sesion"<<endl;	
	gotoxy(57,24);cin.clear(),a=getch();
		t=1;
		if(a=='3'){
		gotoxy(57,18);cout<<"Desea cerrar sesion?(si/no): ";
		while(respo=="")gotoxy(96,18),getline(cin,respo);
		while(respo!="si" && respo!="no"){
			gotoxy(89,18);cout<<"\t\t";
			respo="";
			while(respo=="")gotoxy(89,18),getline(cin,respo);
		}
			if(respo=="no") t=0;
			if(respo=="si")	t=1;
		}
	}
	system("cls");
	return a;
	}
void crear(cuenta usu[],int &usuCont){
	string u,uv;
	int i,j,t=0,a=0,f=0;
	ofstream cuentas("cuentas.txt");
	marco();
	gotoxy(36,2);cout<<"-.-.-.-.-.-.CREA TU CUENTA.-.-.-.-.-.-"<<endl;
	gotoxy(10,7);cout<<"Nombre: ";
	for(int i=40;i<69;i++){
 	gotoxy(i,6);cout<<char(205);
 	gotoxy(i,8);cout<<char(205);
 	}
 	gotoxy(39,7);cout<<char(186);
 	gotoxy(69,7);cout<<char(186);
 	gotoxy(69,6);cout<<char(187);
 	gotoxy(69,8);cout<<char(188);
 	gotoxy(39,6);cout<<char(201);
 	gotoxy(39,8);cout<<char(200);
	gotoxy(10,10);cout<<"Apellido: ";
	for(int i=40;i<69;i++){
 	gotoxy(i,9);cout<<char(205);
 	gotoxy(i,11);cout<<char(205);
 	}
 	gotoxy(39,10);cout<<char(186);
 	gotoxy(69,10);cout<<char(186);
 	gotoxy(69,9);cout<<char(187);
 	gotoxy(69,11);cout<<char(188);
 	gotoxy(39,9);cout<<char(201);
 	gotoxy(39,11);cout<<char(200);
	gotoxy(10,13);cout<<"Usuario: ";
	for(int i=40;i<69;i++){
 	gotoxy(i,12);cout<<char(205);
 	gotoxy(i,14);cout<<char(205);
 	}
 	gotoxy(39,13);cout<<char(186);
 	gotoxy(69,13);cout<<char(186);
 	gotoxy(69,12);cout<<char(187);
 	gotoxy(69,14);cout<<char(188);
 	gotoxy(39,12);cout<<char(201);
 	gotoxy(39,14);cout<<char(200);
	gotoxy(10,16);cout<<"Contrase"<<char(164)<<"a: ";
	for(int i=40;i<69;i++){
 	gotoxy(i,15);cout<<char(205);
 	gotoxy(i,17);cout<<char(205);
 	}
 	gotoxy(39,16);cout<<char(186);
 	gotoxy(69,16);cout<<char(186);
 	gotoxy(69,15);cout<<char(187);
 	gotoxy(69,17);cout<<char(188);
 	gotoxy(39,15);cout<<char(201);
 	gotoxy(39,17);cout<<char(200);
	gotoxy(10,19);cout<<"Reingrese su Contrase"<<char(164)<<"a: "<<endl;
	for(int i=40;i<69;i++){
 	gotoxy(i,18);cout<<char(205);
 	gotoxy(i,20);cout<<char(205);
 	}
 	gotoxy(39,19);cout<<char(186);
 	gotoxy(69,19);cout<<char(186);
 	gotoxy(69,18);cout<<char(187);
 	gotoxy(69,20);cout<<char(188);
 	gotoxy(39,18);cout<<char(201);
 	gotoxy(39,20);cout<<char(200);
	/*gotoxy(50,10);cout<<"PIN: ";
	gotoxy(50,13);cout<<"Correo: ";
	gotoxy(50,16);cout<<"Codigo de Seguridad: "<<endl;*/
	usu[usuCont].usua=="";
	while(usu[usuCont].nombre=="")gotoxy(40,7),getline(cin,usu[usuCont].nombre);
	while(usu[usuCont].apell=="")gotoxy(40,10),getline(cin,usu[usuCont].apell);
	while(usu[usuCont].usua=="")gotoxy(40,13),getline(cin,usu[usuCont].usua);
	while(t==0){
		for(i=0;i<usuCont;i++){
			if(usu[usuCont].usua==usu[i].usua && usuCont!=i){
				gotoxy(75,13);cout<<"Ya existe ese Usuario!"<<endl;
				Sleep(1000);
				gotoxy(40,13);cout<<"\t\t\t\t\t";
				
				gotoxy(10,13);cout<<"Usuario: ";
				usu[usuCont].usua="";
			while(usu[usuCont].usua=="" or usu[usuCont].usua==usu[i].usua){
				gotoxy(40,13),getline(cin,usu[usuCont].usua);
				gotoxy(31,13);cout<<"\t\t\t\t\t\t\t\t";
				gotoxy(75,13);cout<<"Ya existe ese Usuario!"<<endl;
				Sleep(1000);
				}
				gotoxy(75,13);cout<<"\t\t\t\t\t\t\t\t\t\t"<<endl;
			}
		else t=1;
		}
	}
	while(usu[usuCont].contra=="")gotoxy(36,10),getline(cin,usu[usuCont].contra);
	while(u=="")gotoxy(50,12),getline(cin,u);
	while(a==0){
		if(u!=usu[usuCont].contra){
			gotoxy(60,12);cout<<"Las contraseñas no son iguales"<<endl;
			Sleep(1000);
			gotoxy(60,12);cout<<"\t\t\t\t\t\t";
			gotoxy(50,12);cout<<"\t\t\t\t\t\t";
			gotoxy(22,12);cout<<"Reingrese su Contraseña : "<<endl;
			u="";
			while(u=="")gotoxy(50,12),getline(cin,u);
			}
		else a=1;
	}
	while(usu[usuCont].pin=="")gotoxy(28,14),getline(cin,usu[usuCont].pin);
	while(usu[usuCont].correo=="")gotoxy(31,16),getline(cin,usu[usuCont].correo);
	while(f==0){
		for(i=0;i<100;i++){
			if(usu[usuCont].correo==usu[i].correo && usuCont!=i){
				gotoxy(60,16);cout<<"Ya existe una cuenta con este correo!"<<endl;
				Sleep(1000);
				gotoxy(60,16);cout<<"\t\t\t\t\t\t";
				gotoxy(31,16);cout<<"\t\t\t\t\t\t";
				gotoxy(22,16);cout<<"Correo: ";
				usu[usuCont].correo="";
			while(usu[usuCont].correo=="" or usu[usuCont].correo==usu[i].correo){
				gotoxy(31,16),getline(cin,usu[usuCont].correo);
				gotoxy(31,16);cout<<"\t\t\t\t\t\t";
				gotoxy(60,16);cout<<"Ya existe una cuenta con este correo!"<<endl;
				Sleep(1000);
				gotoxy(60,16);cout<<"\t\t\t\t\t\t";
				}
			}
		else f=1;
		}
	}
	while(usu[usuCont].cod=="")gotoxy(44,18),getline(cin,usu[usuCont].cod);
	//cuentas<<usu[usuCont].nombre<<"*"<<usu[usuCont].apell<<"*"<<usu[usuCont].usua<<"*"<<usu[usuCont].contra<<"*"<<usu[usuCont].pin<<"*"<<usu[usuCont].correo<<"*"<<usu[usuCont].cod<<"*"<<endl;
	EscribirArcheage(usu[usuCont]);
	usuCont++;
	gotoxy(22,22);cout<<"Cuenta Creada Exitosamente!"<<endl;
	Sleep(1500);
	system("cls");
}
char mainadmin(int ind){
	int t=0;
	char a;
	string respo="";
	while(t==0){
	system("cls");	
	marco();
	gotoxy(35,3);cout<<"-.-.-.-.-.-.BIENVENIDO, Admin "<<usu[ind].nombre<<"-.-.-.-.-.-"<<endl;
	gotoxy(35,8);cout<<"[1] Administrar cuentas"<<endl;
	gotoxy(35,13);cout<<"[2] Tienda"<<endl;
	gotoxy(35,18);cout<<"[3] Cerrar sesion"<<endl;
	gotoxy(57,24);cin.clear(),a=getch();
		t=1;
		if(a=='3'){
		gotoxy(57,18);cout<<"Deseas cerrar su sesion actual?";
		while(respo=="")gotoxy(89,18),getline(cin,respo);
		while(respo!="si" && respo!="no"){
			gotoxy(89,18);cout<<"\t\t";
			respo="";
			while(respo=="")gotoxy(89,18),getline(cin,respo);
		}
			if(respo=="no") t=0;
			if(respo=="si")	t=1;
		}
	}
	system("cls");
	return a;
	}
void menuadmin(int ind){
	char o;
	int v=1;
	while(v==1){
	o=mainadmin(ind);
	switch(o){
		case '1': //administrar(usu); break;
		case '2': tienda(usu,ind); break;
		case '3': v=0; break;	
	}
	}
}
void PERFIL(cuenta usu[],int ind){ // int 
	string codPermisos;
	char opc;
	system("cls");
	marco();
	gotoxy(24,13);cout<<"Ingrese codigo de seguridad : ";
	gotoxy(55,13);getline(cin,codPermisos);
	if(codPermisos==usu[ind].cod){
		system("cls");
		marco();
		gotoxy(14,3);cout<<"Nombre : "<<usu[ind].nombre<<endl;
		gotoxy(14,5);cout<<"Apellido : "<<usu[ind].apell<<endl;
		gotoxy(14,7);cout<<"Usuario : "<<usu[ind].usua<<endl;
		gotoxy(14,9);cout<<"Contrase"<<char(164)<<"a : "<<usu[ind].contra<<endl;
		gotoxy(14,11);cout<<"PIN : "<<usu[ind].pin<<endl;
		gotoxy(14,13);cout<<"Correo : "<<usu[ind].correo<<endl;
		gotoxy(14,15);cout<<"Codigo de Permisos : "<<usu[ind].cod<<endl;
		gotoxy(14,24);cout<<"Para Modificar presione 'S', sino presione otra tecla : ";opc=getch();
		if(opc=='s' or opc=='S') OPCIONESPERFILMODIFICABLES(usu,ind);
	}
	else{
		system("cls");
		gotoxy(24,12);cout<<"Codigo Errado."<<endl,gotoxy(24,13);cout<<"Sera Redirigido."<<endl;
		Sleep(2000);
	}	
}
void MODIFICANDOPERFIL(cuenta usu[],int ind,char num){
	cin.ignore(256,'\n');	
	switch(num){
		case '1': gotoxy(65,3);cout<<"Nuevo Nombre :";gotoxy(81,3);cin>>usu[ind].nombre; break;
		case '2': gotoxy(65,5);cout<<"Nuevo Apellido :";gotoxy(83,5);cin>>usu[ind].apell; break;
		case '3': gotoxy(65,7);cout<<"Nuevo Usuario :";gotoxy(82,7);cin>>usu[ind].usua; break;
		case '4': gotoxy(65,9);cout<<"Nuevo Contraseña :";gotoxy(84,9);cin>>usu[ind].contra; break;
		case '5': gotoxy(65,11);cout<<"Nuevo PIN :";gotoxy(78,11);cin>>usu[ind].pin; break;
		case '6': gotoxy(65,13);cout<<"Nuevo Correo :";gotoxy(81,13);cin>>usu[ind].correo; break;
		case '7': gotoxy(65,15);cout<<"Nuevo Codigo de Permisos :";gotoxy(92,15);cin>>usu[ind].cod; break;
		default : gotoxy(14,19);cout<<"Opcion Errada."<<endl,gotoxy(14,20);cout<<"Sera Redirigido"<<endl,Sleep(2000); break;
	}
	//cout << "WEWEEWEW";
	//system("PAUSE");
	ActualizarVerga();
}
void OPCIONESPERFILMODIFICABLES(cuenta usu[],int ind){
	char num;	
	system("cls");
	gotoxy(14,3);cout<<"[1] Nombre"<<endl;
	gotoxy(14,5);cout<<"[2] Apellido"<<endl;
	gotoxy(14,7);cout<<"[3] Usuario"<<endl;
	gotoxy(14,9);cout<<"[4] Contraseña"<<endl;
	gotoxy(14,11);cout<<"[5] PIN"<<endl;
	gotoxy(14,13);cout<<"[6] Correo"<<endl;
	gotoxy(14,15);cout<<"[7] Codigo de Permisos"<<endl;
	gotoxy(14,17);cout<<"Ingrese el numero del dato a modificar :";gotoxy(55,17);cin>>num;
	MODIFICANDOPERFIL(usu,ind,num);
}
void VERIFICANDOCUENTA(cuenta usu[],int ind){
	string nom,ape,usuc,con,pon,cor,cud;
	system("cls");
	cin.ignore(1024,'\n');
	cout<<"Nombre : ";
	getline(cin,nom);
	cout<<"Apellido : ";
	getline(cin,ape);
	cout<<"Usuario : ";
	getline(cin,usuc);
	cout<<"Contraseña : ";
	getline(cin,con);
	cout<<"PIN : ";
	getline(cin,pon);
	cout<<"Correo : ";
	getline(cin,cor);
	cout<<"Codigo de Seguridad : ";
	getline(cin,cud);
	if(nom==usu[ind].nombre && ape==usu[ind].apell && usuc==usu[ind].usua && con==usu[ind].contra && pon==usu[ind].pin && cor==usu[ind].correo && cud==usu[ind].cod){
		cout<<"Ingrese nueva contraseña : ";cin>>usu[ind].contra;
		usu[ind].verificador=0;
		cout<<"Guardado"<<endl;
	}
	else{
		cout<<"Datos errados"<<endl;
		cout<<"Ingrese nuevamente y sera redirigido"<<endl;		
	}
	Sleep(2000);
	system("cls");
	main();
}
void tienda(cuenta usu[],int ind){
	app appTemp[5];
	int h=0, saldo=20;
	for(int g=0;g<100;g++){
		usu[g].aplic[0].precio=10;
		usu[g].aplic[1].precio=12;
		usu[g].aplic[2].precio=2;
		usu[g].aplic[3].precio=14;
		usu[g].aplic[4].precio=11;
		
		usu[g].saldo=20.0;
		
		usu[g].aplic[0].nom="Black Ops III";
		usu[g].aplic[1].nom="Grand thef auto V";
		usu[g].aplic[2].nom="Calculadora";
		usu[g].aplic[3].nom="Convertidor de monedas";
		usu[g].aplic[4].nom="Pacman";
	}
	menutienda(usu,h,saldo,ind,appTemp);
}
void menutienda(cuenta usu[], int &h, int saldo,int ind, app appTemp[]){
	char opcion1;
	int opcion;
	int t=0;
	system("cls");
	marco();
	gotoxy(32,3);cout<<"Bienvenido a la tienda"<<endl;
	gotoxy(15,7);cout<<"a. Comprar Aplicaciones";
	gotoxy(15,9);cout<<"b. En carrito";
	gotoxy(15,11);cout<<"c. Tu saldo disponible";
	gotoxy(15,13);cout<<"d. Tus aplicaciones";
	gotoxy(15,15);cout<<"e. Salir de la tienda";
	gotoxy(15,19);cout<<"Opcion a ingresar [  ]";
	gotoxy(34,19);cin>>opcion1;
	while(t==0){
	switch(opcion1){
		case 'a' : case 'A' : compraraplicaciones(usu, h, saldo,ind, opcion, appTemp);
			break;
		case 'b' : case 'B' : carrito(usu, h, saldo,ind, appTemp, opcion);
			break;
		case 'c' : case 'C' : tusaldo(usu, h, saldo,ind, opcion, appTemp);
			break;
		case 'd' : case 'D' : tusaplicaciones(usu, h, saldo,ind, appTemp);
			break;
		case 'e' : case 'E' : t=1;//SALIR AL MENU PRINCIPAL
			break;
	}
	}
}
void compraraplicaciones(cuenta usu[], int &h, int saldo,int ind, int opcion, app appTemp[]){ //hize cambios aqui
	system("cls");
	marco();
	gotoxy(70,4);cout<<usu[ind].saldo<<" $";
	gotoxy(30,5);cout<<"Compra de aplicaciones"<<endl;
	gotoxy(10,7);cout<<"Aplicaciones en oferta";
	gotoxy(7,9);cout<<"1 . BlackOps III";
	gotoxy(7,10);cout<<"2 . Grand thef auto V";
	gotoxy(7,11);cout<<"3 . Calculadora";
	gotoxy(7,12);cout<<"4 . Convertidor de monedas";
	gotoxy(45,7);cout<<"De mayor compra";
	gotoxy(42,9);cout<<"5 . Pacman";
	gotoxy(42,13);cout<<"0. Salir";
	gotoxy(12,14);cout<<"Opcion a ingresar [  ]";
	gotoxy(31,14),cin>>opcion;
	if(opcion==0){
		menutienda(usu ,h, saldo,ind, appTemp);
	}
	MenuAplicacion(usu ,h, opcion, saldo,ind, appTemp);
}

void MenuAplicacion(cuenta usu[], int &h, int opcion, int saldo,int ind, app appTemp[]){
	string opcion1;
	char cadenaLeer[100];
	bool siguiente = true;
	char letra;
	ifstream convertor("Convertidor.txt");
	//ofstream salida("Black ops 3.txt");
	system("cls");
	marco();
	gotoxy(70,4);cout<<usu[ind].saldo<<" $";
	
	gotoxy(34,5);cout<<usu[ind].aplic[opcion-1].nom;
	/*
	if(opcion==1)
		gotoxy(10,7);ofstream salida("Black ops 3.txt");
	if(opcion==2)
		gotoxy(10,7);ofstream salida("Grand Thef Auto V.txt");
	if(opcion==3)
		gotoxy(10,7);ofstream salida("Calculadora.txt");
	*/if(!convertor){
		gotoxy(34,10);cout<<"No hay descripcion de la aplicacion"<<endl;
		Sleep(40);
		compraraplicaciones(usu, h, saldo,ind, opcion, appTemp);
	}
	if(opcion==4){
		while(siguiente){
			for(int y=0;y<20;y++){
				convertor.getline(cadenaLeer,100);
				gotoxy(10,y+7);cout<<cadenaLeer<<" ";
			}
			siguiente=convertor.get(letra);
		}
	}
	/*if(opcion==5)
		gotoxy(10,7);ofstream salida("Pacman.txt");
		*/
	gotoxy(12,20);cout<<"Desea mandar al carrito ? si/no [  ]";
	gotoxy(45,20),cin>>opcion1;
	if(opcion1=="si"||opcion1=="SI"){
		
		appTemp[h].nom = usu[ind].aplic[opcion-1].nom;
		appTemp[h].precio = usu[ind].aplic[opcion-1].precio;
		h++;
		carrito(usu, h, saldo,ind, appTemp, opcion);
		
	}
	else
		compraraplicaciones(usu, h, saldo,ind,opcion, appTemp);
}


void carrito(cuenta usu[], int &h, int &saldo,int ind, app appTemp[], int opcion){
	
	float compraTotal=0.0;
	string opcion1, opcion2;
	system("cls");
	marco();
	gotoxy(70,4);cout<<usu[ind].saldo<<" $";
	
	gotoxy(30,5);cout<<"Carrito de Compras";
	gotoxy(10,7);cout<<"En el carrito : ";
	
	for(int j=9;j<h+9;j++){
		gotoxy(7,j);cout<<j-8<<" . "<<appTemp[j-9].nom<<" -Con precio de $ "<<appTemp[j-9].precio;
		compraTotal = compraTotal + appTemp[j-9].precio;
	}
	gotoxy(12,16);cout<<"Desea adquirir el carrito? si/no [   ]";
	gotoxy(46,16),cin>>opcion1;
	if(opcion1=="si"||opcion1=="SI"){
		
		if(saldo>=compraTotal){
			gotoxy(12,18);cout<<"Juego(s) Comprados ...";
			usu[ind].saldo=usu[ind].saldo - compraTotal;
			if(h==1)
				usu[ind].myaplic[0].nom = appTemp[0].nom;
				usu[ind].myaplic[1].nom = " ";
				usu[ind].myaplic[2].nom = " ";
				usu[ind].myaplic[3].nom = " ";
				usu[ind].myaplic[4].nom = " ";
			if(h==2){
				usu[ind].myaplic[0].nom = appTemp[0].nom;
				usu[ind].myaplic[1].nom = appTemp[1].nom;
				usu[ind].myaplic[2].nom = " ";
				usu[ind].myaplic[3].nom = " ";
				usu[ind].myaplic[4].nom = " ";
			}
			if(h==3){
				usu[ind].myaplic[0].nom = appTemp[0].nom;
				usu[ind].myaplic[1].nom = appTemp[1].nom;
				usu[ind].myaplic[2].nom = appTemp[2].nom;
				usu[ind].myaplic[3].nom = " ";
				usu[ind].myaplic[4].nom = " ";
			}				
			if(h==4){
				usu[ind].myaplic[0].nom = appTemp[0].nom;
				usu[ind].myaplic[1].nom = appTemp[1].nom;
				usu[ind].myaplic[2].nom = appTemp[2].nom;
				usu[ind].myaplic[3].nom = appTemp[3].nom;
				usu[ind].myaplic[4].nom = " ";
			}
			if(h==5){
				usu[ind].myaplic[0].nom = appTemp[0].nom;
				usu[ind].myaplic[1].nom = appTemp[1].nom;
				usu[ind].myaplic[2].nom = appTemp[2].nom;
				usu[ind].myaplic[3].nom = appTemp[3].nom;
				usu[ind].myaplic[4].nom = appTemp[4].nom;
			}	
			menutienda(usu, h, saldo,ind, appTemp);
		}else{
			gotoxy(12,16);cout<<"No tiene saldo disponible";
			
			gotoxy(12,18);cout<<"Deseas limpiar el carrito? si/no [   ]";
			gotoxy(46,18);cin>>opcion2;
			if(opcion1=="si"||opcion1=="SI"){
				tienda(usu, ind);
			}
				
			else{
				menutienda(usu, h, saldo,ind, appTemp);
		}
		}
			
	}else{
		
		gotoxy(12,18);cout<<"Deseas limpiar el carrito? si/no [   ]";
		gotoxy(46,18);cin>>opcion2;
		if(opcion1=="si"||opcion1=="SI"){
			tienda(usu, ind);
		}
			
		else{
			menutienda(usu, h, saldo,ind, appTemp);
		}
		
	}
}
void tusaldo( cuenta usu[], int h, int saldo,int ind, int opcion, app apptemp[]){
	string opcion2;
	system("cls");
	marco();
	gotoxy(70,4);cout<<usu[ind].saldo<<" $";
	gotoxy(10,7);cout<<"Aprovecha las ofertas ";
	gotoxy(7,9);cout<<"5 . Pacman";

	gotoxy(12,14);cout<<"Deseas ingresar a la tienda ? si/no [  ]";
	gotoxy(48,14),cin>>opcion2;
	if(opcion2=="si"||opcion2=="SI")
		compraraplicaciones(usu, h, saldo,ind,opcion, apptemp);
	else
		menutienda(usu, h, saldo,ind, apptemp);
}
void tusaplicaciones(cuenta usu[], int h, int saldo,int ind, app appTemp[]){
	int opcion1;
	system("cls");
	marco();
	gotoxy(70,4);cout<<usu[ind].saldo<<" $";
	
	gotoxy(10,7);cout<<"Tus Aplicaciones";

	for(int k=9;k<3+9;k++){
		gotoxy(7,k);cout<<k-8<<". "<<usu[0].myaplic[k-9].nom;
	}
	
	gotoxy(10,17);cout<<"Aplicacion a ingresar [  ]";
	gotoxy(10,18);cout<<"Digite 0 para salir";
	gotoxy(33,17),cin>>opcion1;
	if(opcion1==0)
		menutienda(usu, h, saldo,ind, appTemp);
		
	for(int o=1; o<6; o++){
		if(opcion1 == o){
			//if(usu[ind].myaplic[o-1].nom == usu[ind].aplic[0].nom)
				//blackops3();
			//if(usu[ind].myaplic[o-1].nom == usu[ind].aplic[1].nom)
				//gtaV();
			//if(usu[ind].myaplic[o-1].nom == usu[ind].aplic[2].nom)
				//calculadora();
			if(usu[ind].myaplic[o-1].nom == usu[ind].aplic[3].nom)
				convertidor();
			//if(usu[ind].myaplic[o-1].nom == usu[ind].aplic[4].nom)
				//pacman();
		}
	}
}
int convertidor(){
tipocambio valores={1,3.28,3.5,4};
menucambio(valores);
}
void menucambio(tipocambio valores){
	cin.ignore(256,'\n');
	int v=1;
	int s,d,e,l,b;
	char opc,o;
	while(v==1){
	o=MenuCambioA();
	switch(o){
		case '1':
			system("cls");
			marco();
        	gotoxy(24,6); cout<<"Ingrese Cantidad de Soles: "; cin>>s;
			gotoxy(24,8);cout<<"Ingrese Moneda a Cambiar:"<<endl;
			gotoxy(24,9);cout<<"[1]..Dolar"<<endl;
			gotoxy(24,10);cout<<"[2]..Euro"<<endl;
			gotoxy(24,11);cout<<"[3]..Libra"<<endl;
       	 	gotoxy(24,12),cout<<"Opcion: ";cin>>b;
				switch(b){
					case 1:
					gotoxy(8,14);cout<<"Total de dolares: ";
					gotoxy(28,14);cout<< s/valores.dolar<<endl;
					break;
					case 2:
					gotoxy(8,14);cout<<"Total de Euros: ";
					gotoxy(28,14);cout<< s/valores.euro<<endl;
					break;
					case 3:
					gotoxy(8,14);cout<<"Total de Libras: ";
					gotoxy(28,14);cout<< s/valores.libra<<endl;
					break;
				}
				break;
		case '2':
		system("cls");
        gotoxy(24,6);cout<<"Ingrese Cantidad de Dolares: ";cin>>d;
        gotoxy(24,8);cout<<"Ingrese Moneda a Cambiar:"<<endl;
        gotoxy(24,9);cout<<"[1]..Soles"<<endl;
        gotoxy(24,10);cout<<"[2]..Euro"<<endl;
        gotoxy(24,11); cout<<"[3]..Libra"<<endl;
        gotoxy(24,12),cout<<"Opcion: ";cin>>b;
				switch(b){
					case 1:
                    gotoxy(8,14);cout<<"Total de Soles: ";
                    gotoxy(28,14);cout<< d*valores.dolar<<endl;
					break;
					case 2:
                    gotoxy(8,14);cout<<"Total de Euros: ";
                    gotoxy(28,14);cout<< (d*valores.dolar)/valores.euro<<endl;
					break;
					case 3:
                    gotoxy(8,14);cout<<"Total de Libras: ";
					gotoxy(28,14);cout<< (d*valores.dolar)/valores.libra<<endl;
					break;
				}
				break;

		case '3':
		system("cls");
        gotoxy(24,6);cout<<"Ingrese Cantidad de Euros: ";cin>>e;
        gotoxy(24,8); cout<<"Ingrese Moneda a Cambiar:"<<endl;
        gotoxy(24,9);cout<<"[1]..Soles"<<endl;
        gotoxy(24,10);cout<<"[2]..Dolares"<<endl;
        gotoxy(24,11);cout<<"[3]..Libra"<<endl;
        	gotoxy(24,12),cout<<"Opcion: ";cin>>b;
				switch(b){
					case 1:
					gotoxy(8,14);cout<<"Total de Soles: ";
					gotoxy(28,14);cout<< e*valores.euro<<endl;
					break;
					case 2:
					gotoxy(8,14);cout<<"Total de dolares: ";
					gotoxy(28,14);cout<< (e*valores.euro)/valores.dolar<<endl;
					break;
					case 3:
					gotoxy(8,14);cout<<"Total de Libras: ";
					gotoxy(28,14);cout<< (e*valores.euro)/valores.libra<<endl;
					break;
				}
				break;
		case '4':
		system("cls");
         gotoxy(24,6);cout<<"Ingrese Cantidad de Libras: ";cin>>l;
         gotoxy(24,8);cout<<"Ingrese Moneda a Cambiar:"<<endl;
         gotoxy(24,9);cout<<"[1]..Soles"<<endl;
         gotoxy(24,10);cout<<"[2]..Dolares"<<endl;
         gotoxy(24,11);cout<<"[3]..Euros"<<endl;
        	gotoxy(24,12),cout<<"Opcion: ";cin>>b;
				switch(b){
					case 1:
					gotoxy(8,14);cout<<"Total de Soles: ";
					gotoxy(28,14);cout<< l*valores.libra<<endl;
					break;
					case 2:
					gotoxy(8,14);cout<<"Total de Dolares: ";

					gotoxy(28,14);cout<< (l*valores.libra)/valores.dolar<<endl;
					break;
					case 3:
					gotoxy(8,14);cout<<"Total de Euros: ";
					gotoxy(28,14);cout<< (l*valores.libra)/valores.euro<<endl;
					break;
				}
				break;
	}
	gotoxy(4,16);cout<<"Si desea volver al convertidor presione la tecla S: ";cin>>opc;
	if(opc == 'S' or opc == 's')
	v=1;
	else v=0;
	}
}
char MenuCambioA(){
	char a;
	system("cls");
	marco();
	gotoxy(28,8);cout<<"Ingrese Moneda a Cambiar"<<endl;
	gotoxy(28,9);cout<<"[1]..Nuevo Sol"<<endl;
	gotoxy(28,10);cout<<"[2]..Dolar"<<endl;
	gotoxy(28,11);cout<<"[3]..Euro"<<endl;
	gotoxy(28,12);cout<<"[4]..Libra"<<endl;
    gotoxy(28,14);cout<<"Opcion: ";cin>>a;
system("cls");
	return a;
}

void SobreEscribir(cuenta a,ofstream &lala){
	//ofstream lalo("pinguino.txt",ios::app);
	
	lala << a.nombre << "*"
		<< a.apell << "*"
		<< a.usua << "*"
		<< a.contra << "*"
		<< a.pin << "*"
		<< a.correo << "*"
		<< a.cod << "*"
		<<endl;
	
	//lala.close();	
}

void ActualizarVerga()
{
	ofstream lalo("pinguino.txt",ios::trunc);
	int r;
	for(r=aggtmr;r<usuCont-1;r++){
	/*	lalo << usu[r].nombre << "*"
		<< usu[r].apell << "*"
		<< usu[r].usua << "*"
		<< usu[r].contra << "*"
		<< usu[r].pin << "*"
		<< usu[r].correo << "*"
		<< usu[r].cod << "*"
		<<endl;*/
		SobreEscribir(usu[r],lalo);	
		/*cout << "MIERDA"<< usu[r].apell<<r<<usuCont<<endl;
		cout << "MIERDA"<<endl;cout << "\nMIERDA"<<endl;cout << "\nMIERDA"<<endl;
		cout << "MIERDA"<<endl;cout << "\nMIERDA"<<endl;cout << "\nMIERDA"<<endl;cout << "\nMIERDA"<<endl;cout << "\nMIERDA"<<endl;cout << "\nMIERDA"<<endl;
		cout << "MIERDA"<<endl;
		cout << "MIERDA"<<endl;
		cout << "MIERDA"<<endl;
		system("PAUSE");*/
	
	}
	lalo.close();
}


void LeerArcheage()
{
	bool wew=true;
	char asd;
	ifstream tera("pinguino.txt");
	char a1[30];
	char a2[30];
	char a3[30];
	char a4[30];
	char a5[30];
	char a6[30];
	char a7[30];
	int i=aggtmr;
	
	while(wew){
		tera.getline(a1,30,'*');
		tera.getline(a2,30,'*');
		tera.getline(a3,30,'*');
		tera.getline(a4,30,'*');
		tera.getline(a5,30,'*');
		tera.getline(a6,30,'*');
		tera.getline(a7,30,'*');
		usu[i].nombre=a1;
		usu[i].apell=a2;
		usu[i].usua=a3;
		usu[i].contra=a4;
		usu[i].pin=a5;
		usu[i].correo=a6;
		usu[i].cod=a7;
		i++;
		usuCont++;
		wew=tera.get(asd);
		
			
	}
	
}

void EscribirArcheage(cuenta a){
	ofstream lelo("pinguino.txt",ios::app);
	
	lelo << a.nombre << "*"
		<< a.apell << "*"
		<< a.usua << "*"
		<< a.contra << "*"
		<< a.pin << "*"
		<< a.correo << "*"
		<< a.cod << "*"
		<<endl;
	
	lelo.close();	
}
