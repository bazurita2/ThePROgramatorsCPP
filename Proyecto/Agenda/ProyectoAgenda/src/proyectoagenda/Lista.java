/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package proyectoagenda;

/**
 *
 * @author USUARIO
 */
public class Lista {
    private Nodo inicio;
 
    private int tamanio;
  
    public void Lista(){
        inicio = null;
        tamanio = 0;
    }
   
    public boolean esVacia(){
        return inicio == null;
    }
   
    public int getTamanio(){
        return tamanio;
    }
    
    public void agregarAlInicio(long teleCasa,long celu,String nomb,String apell){
       
        Nodo nuevo = new Nodo();
        Archivo archivo = new Archivo();
        
        nuevo.setTelefonoCasa(teleCasa);
	nuevo.setCelular(celu);
	nuevo.setNombre(nomb);
	nuevo.setApellido(apell);
        
        archivo.guardar("Agenda.csv",nuevo);
       
        if (esVacia()) {
            
            inicio = nuevo;
        
        } else{
           
            nuevo.setSiguiente(inicio);
           
            inicio = nuevo;
        }
       
        tamanio++;
    }
    
     public void agregarAlInicioCampoExtra(long cedula,int cumpleDia,int cumpleMes,int cumpleAnio,String correo,String direccion,int aniverDia,int aniverMes,int aniverAnio,String nota){
       
        Nodo nuevo = new Nodo();
        Archivo archivo = new Archivo();
        
        nuevo.setCedula(cedula);
        nuevo.setCumpleDia(cumpleDia);
        nuevo.setCumpleMes(cumpleMes);
        nuevo.setCumpleAnio(cumpleAnio);
        nuevo.setCorreo(correo);
        nuevo.setDireccion(direccion);
        nuevo.setAniverDia(aniverDia);
        nuevo.setAniverMes(aniverMes);
        nuevo.setAniverAnio(aniverAnio);
        nuevo.setNota(nota);
        
        archivo.guardar("Agenda.csv",nuevo);
       
        if (esVacia()) {
            
            inicio = nuevo;
        
        } else{
           
            nuevo.setSiguiente(inicio);
           
            inicio = nuevo;
        }
       
        tamanio++;
    }
    
    
      public void listar(){
        
          
          
        if (!esVacia()) {
            
            Nodo aux = inicio;
            
            while(aux != null){
                
                System.out.println("");
                System.out.print("\nNombre: "+aux.getNombre());
                System.out.println("\nApellido: "+aux.getApellido());
                System.out.println("\nCelular: "+aux.getCelular());
                System.out.println("\nTelefono casa: "+aux.getTelefonoCasa());
                               
                aux = aux.getSiguiente();
                
                //falta imprimir los datos extras
            
            }
        }
    }

  
      
}
