/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package proyectoagenda;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

/**
 *
 * @author USUARIO
 */
public class Archivo {
    
    public Archivo(){
        
    }
    
    public void guardar(String fileName, Nodo contacto)
    {
        try
        {
             File file=new File(fileName);
               if (!file.exists()) {
                   file.createNewFile();
                 }
             FileWriter wr=new FileWriter(file.getAbsoluteFile(),true);
             BufferedWriter bw = new BufferedWriter(wr);
             wr.write("\n"+"\nNombre: "+";"+contacto.getNombre()+"\nApellido: "+";"+contacto.getApellido()+"\nCelular: "+";"+"0"+contacto.getCelular()+"\nTelefono de casa: "+";"+contacto.getTelefonoCasa()+"\n");
             wr.close();
             bw.close();
        } catch (IOException e)  {
          System.out.println("ERROR: No se pudo escribir en el archivo");
        }
       
    }
    
   public void leer(String fileName)
    {
        
        File file =new File(fileName);
        FileReader fileread;
        BufferedReader buffer;
        
           if (!file.exists()) {
              System.out.println("ERROR: El archivo no existe");
              return;
              }
   
        try {
	   fileread = new FileReader(file);
	   buffer = new BufferedReader(fileread);
	   String lines;
         while((lines=buffer.readLine())!=null) {
	       System.out.println(lines);
               }
         fileread.close();
        } catch (IOException e) {
           System.out.println("ERROR: No se pudo abrir el archivo");
            
       }
     
    } 
   public void modificar(String oldText, String newText ,String name)
    {
         try
            {
                    BufferedReader a = new BufferedReader(new FileReader(name));
                    String line;
                    String input = "";
                    while ((line = a.readLine()) != null) 
                    {
                        input = input + line + "\n";
                    }

                    input=input.replace(oldText,newText);
                    FileOutputStream getText = new FileOutputStream(name);
                    getText.write(input.getBytes());
                    a.close();
                    getText.close();

            }
            catch (IOException e)
            {
               System.out.println("Un error a ocurrido, inténtelo más tarde");
            }

    }
   
    public void borrarArchivo(String fileName) throws IOException {
        File file = new File(fileName);
        
        if (file.delete()) {
            System.out.println("El fichero ha sido borrado satisfactoriamente");
        } else {
            file.deleteOnExit();
            BufferedWriter bw = new BufferedWriter(new FileWriter(fileName));
            bw.write("");
            bw.close();
            System.out.println("El fichero no pudó ser borrado");
        }
    }
    
    public void borrarContacto(String delete, String file){        
      try
        {
                BufferedReader rd = new BufferedReader(new FileReader(file));
                String line;
                String input = "";
                while ((line = rd.readLine()) != null) 
                {
                    //System.out.println(line);
                    if (line.contains(delete))
                    {
                        //espacio
                        line = "\n";
                    }
                    input += line;
                }
                FileOutputStream getText = new FileOutputStream(file);
                getText.write(input.getBytes());
                rd.close();
                getText.close();       
        }
        catch (Exception e)
        {
           System.out.println("ERROR: No se pudo abrir el archivo");
        }
      }
}
