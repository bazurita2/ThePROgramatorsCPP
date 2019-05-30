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
    
    public void agregarAlInicio(long teleCasa,long celu,String nomb,String apell,String opc){
       
        Nodo nuevo = new Nodo();
        
        
        nuevo.setTelefonoCasa(teleCasa);
	nuevo.setCelular(celu);
	nuevo.setNombre(nomb);
	nuevo.setApellido(apell);
       
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
                
            
            }
        }
    }
      
}
