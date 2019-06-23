
package connectivity;

import com.mysql.jdbc.Connection;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.util.Random;

public class Conexion 
{
    PreparedStatement ps;
     ResultSet ra;
     String name;
     String ap;
     String tel;
     String cel;
     String mail;
     String ced;
     String dir;
     String cump;
     String ann;
     String note;
    public Connection getConnection()
    {
        Connection con=null;
        try
        {
            Class.forName("com.mysql.jdbc.Driver");
            con= (Connection) DriverManager.getConnection("jdbc:mysql://localhost:3306/agenda","root","");
        }
        catch (Exception ex)
        {
            System.out.println("ERROR: No se pudo conectar a base de datos\n");
            System.out.println(ex);
        }
        return con;
    }
    public void save()
    {
           read();
           Random aleatorio = new Random(System.currentTimeMillis());
           int intAletorio = aleatorio.nextInt(100);
           
           Connection con=null;
           try
           {
              con=getConnection();
              ps=con.prepareStatement("INSERT INTO directorio (clave, nombre, apellido, telefono, celular, correo, direccion, cedula, cumpleanos, aniversario, nota) VALUES(?,?,?,?,?,?,?,?,?,?,?) "); 
              ps.setString(1,String.valueOf(intAletorio));
              ps.setString(2,name);
              ps.setString(3,ap);
              ps.setString(4,tel);
              ps.setString(5,cel);
              ps.setString(6,mail);
              ps.setString(7,ced);
              ps.setString(8,dir);
              ps.setString(9,cump);
              ps.setString(10,ann);
              ps.setString(11,note);
              int res= ps.executeUpdate();
              if(res>0)
              {
                  System.out.println("Elemento Guardado en Base de Datos");
              }
              else
              {
                  System.out.println("ERROR: Elemento no guardado");
              }
              aleatorio.setSeed(System.currentTimeMillis());
              con.close();
           }
           catch(Exception ex)
           {
                System.out.println("ERROR: No se pudo conectar a base de datos\n");
                System.out.println(ex);
           }
           
           
    }
    
    public void read()
    {
        int cont=0;
        try (BufferedReader br = new BufferedReader(new FileReader("db.txt"))) 
        {
        
        String line;
        while ((line = br.readLine()) != null) 
        {
            if(cont==0)
            {
               name=line;
               cont++;  
            }
            else if(cont==1)
            {
                ap=line; 
                cont++;
            }
            else if(cont==2)
            {
                tel=line; 
                cont++;
            }
            else if(cont==3)
            {
               cel=line; 
                 cont++;
            }
             else if(cont==4)
            {
                mail=line; 
                cont++;
            }
            else if(cont==5)
            {
                dir=line; 
                cont++;
            }
            else if(cont==6)
            {
                ced=line; 
                 cont++;
            }    
            else if(cont==7)
            {
                 cump=line; 
                  cont++;
            }
            else if(cont==8)
            {
                ann=line; 
                cont++;
            }
            else if(cont==9)
            {
                note=line; 
                break;
            } 
                   
         }
        try
        {
           br.close();
           new File("db.txt").delete();
        }catch(Exception ex)
        {
              System.out.println("ERROR: No se pudo procesar los datos para imprimir\n");
              System.out.println(ex); 
        }
        
        
     }
      catch(Exception ex)
     {
          System.out.println("ERROR: No se pudo procesar los datos para imprimir\n");
          System.out.println(ex);
     }
        
    }
    
}
