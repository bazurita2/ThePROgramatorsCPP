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
public class Nodo {
    private     Nodo siguiente;
    private     long cedula;
    private	long telefonoCasa;
    private	int cumpleDia;
    private	int cumpleMes;
    private	int cumpleAnio;
    private	int aniverDia;
    private	int aniverMes;
    private	int aniverAnio;
    private	long celular;
    private	String nombre;
    private	String apellido;
    private	String correo;
    private	String nota;
    private	String direccion;

    public Nodo() {
    }

    public Nodo getSiguiente() {
        return siguiente;
    }

    public long getCedula() {
        return cedula;
    }

    public long getTelefonoCasa() {
        return telefonoCasa;
    }

    public int getCumpleDia() {
        return cumpleDia;
    }

    public int getCumpleMes() {
        return cumpleMes;
    }

    public int getCumpleAnio() {
        return cumpleAnio;
    }

    public int getAniverDia() {
        return aniverDia;
    }

    public int getAniverMes() {
        return aniverMes;
    }

    public int getAniverAnio() {
        return aniverAnio;
    }

    public long getCelular() {
        return celular;
    }

    public String getNombre() {
        return nombre;
    }

    public String getApellido() {
        return apellido;
    }

    public String getCorreo() {
        return correo;
    }

    public String getNota() {
        return nota;
    }

    public String getDireccion() {
        return direccion;
    }

    

    public void setSiguiente(Nodo siguiente) {
        this.siguiente = siguiente;
    }

    public void setCedula(long cedula) {
        this.cedula = cedula;
    }

    public void setTelefonoCasa(long telefonoCasa) {
        this.telefonoCasa = telefonoCasa;
    }

    public void setCumpleDia(int cumpleDia) {
        this.cumpleDia = cumpleDia;
    }

    public void setCumpleMes(int cumpleMes) {
        this.cumpleMes = cumpleMes;
    }

    public void setCumpleAnio(int cumpleAnio) {
        this.cumpleAnio = cumpleAnio;
    }

    public void setAniverDia(int aniverDia) {
        this.aniverDia = aniverDia;
    }

    public void setAniverMes(int aniverMes) {
        this.aniverMes = aniverMes;
    }

    public void setAniverAnio(int aniverAnio) {
        this.aniverAnio = aniverAnio;
    }

    public void setCelular(long celular) {
        this.celular = celular;
    }

    public void setNombre(String nombre) {
        this.nombre = nombre;
    }

    public void setApellido(String apellido) {
        this.apellido = apellido;
    }

    public void setCorreo(String correo) {
        this.correo = correo;
    }

    public void setNota(String nota) {
        this.nota = nota;
    }

    public void setDireccion(String direccion) {
        this.direccion = direccion;
    }

}
  
