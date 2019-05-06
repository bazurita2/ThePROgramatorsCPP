//void busquedaBinaria();
//void busquedaBinaria(){
//	string palabras[] = {"Como","Estas","Hola","Innova"};
//	int mitad,superior, inferior;
//	string buscarPalabra;
//	bool validacion=false;
//	inferior=0;
//	superior=4-1;
//	buscarPalabra="Hola";
//	
//	while(inferior<=superior){
//		mitad=(inferior+superior)/2;
//		if(palabras[mitad]==buscarPalabra){
//			validacion=true;
//			break;
//		}
//		if(palabras[mitad]>buscarPalabra){
//			superior= mitad;
//			mitad=(inferior+superior)/2;
//		}
//		if(palabras[mitad]<buscarPalabra){
//			inferior=mitad;
//			mitad=(inferior+superior)/2;
//		}
//	}
//	
//	if(validacion==true){
//		cout<<"se encontro en la pocicion "<<mitad<<endl;
//	}else{
//		cout<<"no se encontro"<<endl;
//	}
//}


//void busquedaSecuencial(){
//	string palabras[] = {"Como","Estas","Hola","Innova"};
//	string buscarPalabra;
//	int i=0;
//	bool validacion=false;
//	
//	buscarPalabra="Como";
//	
//	while((validacion==false)&&(i<4)){
//		if(palabras[i]==buscarPalabra){
//			validacion==true;
//		}
//		i++;
//	}
//	cout<<validacion;
//	if(validacion==true){
//		cout<<"se encontro en la pocicion "<<i-1<<endl;
//	}else{
//		cout<<"no se encontro la palabra"<<endl;
//	}
