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
      int op=0,cumpleDia,cumpleMes,cumpleAnio,aniverDia,aniverMes,aniverAnio;
      String nombre,apellido,nota,correo,direccion;
      char opcion;
      long celu,teleCasa,cedula;
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
                
                agenda.agregarAlInicio(teleCasa, celu, nombre, apellido);
                
                System.out.println("\nAgregar mas campo de contacto? (S/N)");
                opcion=in.next().charAt(0);
                if(opcion=='S'||opcion=='s'){
                    //long cedula,int cumpleDia,int cumpleMes,int cumpleAnio,String correo,String direccion,int aniverDia,int aniverMes,int aniverAnio,String nota
                    System.out.print("Digite su cedula: ");
                    cedula=in.nextLong();
                    System.out.print("Digite el dia de su cumpleaños: ");
                    cumpleDia=in.nextInt();
                    System.out.print("Digite el mes de su cumpleaños: ");
                    cumpleMes=in.nextInt();
                    System.out.print("Digite el anio de su cumpleaños: ");
                    cumpleAnio=in.nextInt();
                    System.out.print("Digite su correo: ");
                    correo=in.next();
                    System.out.print("Digite su direccion: ");
                    direccion=in.next();
                    System.out.print("Digite el dia de su aniversario: ");
                    aniverDia=in.nextInt();
                    System.out.print("Digite el mes de su aniversario: ");
                    aniverMes=in.nextInt();
                    System.out.print("Digite el anio de su aniversario: ");
                    aniverAnio=in.nextInt();
                    System.out.print("Digite una nota para el contacto: ");
                    nota=in.next();
                    agenda.agregarAlInicioCampoExtra(cedula, cumpleDia, cumpleMes, cumpleAnio, correo, direccion, aniverDia, aniverMes, aniverAnio, nota);
                    
                }else{
                    System.out.println("Contacto agregado");
                }
                
                break;
            case 2:
                agenda.listar();
        }
        
       }while(op!=3);
        
        
    }
    
    
    
}
