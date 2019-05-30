/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package proyectoagenda;

import java.util.Scanner;

/**
 *
 * @author USUARIO
 */
public class ProyectoAgenda {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
       //Obvio hay que usar interfaz
       Scanner in=new Scanner(System.in);
       Lista agenda = new Lista();
      int op=0;
      String nombre,apellido;
      long celu,teleCasa;
       do{
        System.out.println("Menu");
        System.out.println("1) Agregar contacto");
        System.out.println("2) Mostrar");
        System.out.println("3) Salir");
           System.out.println("Digite una opcion");
           op=in.nextInt();
        switch(op){
            case 1:
                System.out.print("Ingrese su nombre: ");
                nombre=in.next();
                System.out.print("Ingrese su apellido: ");
                apellido=in.next();
                System.out.print("Ingrese su celular: ");
                celu=in.nextLong();
                System.out.print("Ingrese su telefono de casa: ");
                teleCasa=in.nextLong();
                                
                agenda.agregarAlInicio(teleCasa, celu, nombre, apellido, nombre);
                break;
            case 2:
                agenda.listar();
        }
        
       }while(op!=3);
        
        
    }
    
    
    
}
