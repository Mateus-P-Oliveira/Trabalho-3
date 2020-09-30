//Exercicio 01
//Mateus Pinto de Oliveira
//23/09/20

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>

using namespace std;

#define MAX_ALUNOS 10

class Aluno{
    int nRoMatricula;
    string nome;
    double nota;
public:
    Aluno(int Matricula = 0, string N = "", double Nota=-1.0){ 
        nRoMatricula = Matricula;
        nome = N;
        nota = Nota;
    }
    void defineMatricula(int Matricula){
        nRoMatricula = Matricula;
    }   
    void defineNome(string N){
        nome = N;
    }
    void defineNota(double Nota){
        nota = Nota;
    }
    int obtemMatricula(){
        return nRoMatricula;
    }
    string obtemNome(){
        return nome;
    }
    double obtemNota(){
        return nota;
    }
    string str(){
        stringstream ss;
        ss << nome << "(" << setfill('0') << setw(10) << nRoMatricula << ")";
        if(nota != -1.0) ss << ":" << setw(4) << nota;
        return ss.str();//Converte para string
    }

};

class Turma{
    int nroTurma, nroAlunos;
    string nomeDisciplina, professor;
    Aluno *A[10];
public:
    Turma(int Turma = 0, string Disc = "",string profe = "",int Alunos = 0){
        nroAlunos = Alunos;
        nroTurma = Turma;
        nomeDisciplina = Disc;
        professor = profe;
    }    
    int obtemNumero(){
        return nroTurma;
    }
    string obtemDisciplina(){
        return nomeDisciplina;
    }
    string obtemProfessor(){
        return professor;
    }
    int obtemNumAlunos(){
        return nroAlunos;
    }
    Aluno* obtemAluno(int index){
        if(index < 0 || index >= nroAlunos) return nullptr;
        
        return A[index];
    }
    void defineNumero(int Nu){
        nroTurma = Nu;
    }
    void defineDisciplina(string S){
        nomeDisciplina = S;
    }
    void defineProfessor(string P){
        professor = P;
    }
    bool adicionaAluno(Aluno *P){
        if(nroAlunos == 9) return false;
        A[nroAlunos] = P; 
        delete P;
      
        nroAlunos++;
        return true;
    }
    double calculaMedia(){
        if(nroAlunos > 0){
            double Media = 0;
            for(int i = 0; i < nroAlunos; i++){
                Media = A[i]->obtemNota() + Media;
            }

            return Media;
        }
        else{
            return -1.0;
        }
    }
    string str(){
        stringstream ss;
        ss << nroTurma << "-" << nomeDisciplina << "-Prof." << professor;
        if(nroAlunos > 0){
            for(int i = 0; i < nroAlunos; i++){
                ss << A[i]->str();
            }
        }
        if(nroAlunos > 0) ss << "MEDIA=" << setw(4) << calculaMedia(); 
        return ss.str();
    }

};

int main(){
    Aluno *discente[] = {
    new Aluno(1,"Benedito",9.1),
    new Aluno(2,"Carlos",8.2),
    new Aluno(3,"Daniela",7.3),
    new Aluno(4,"Elisabeth",6.4),
    new Aluno(5,"Fernanda",5.5),
    new Aluno(6,"Gilson",9.6),
    new Aluno(7,"Heitor",8.5),
    new Aluno(8,"Irineu",7.4),
    new Aluno(9,"Joana",3.2),
    new Aluno(10,"Klaus",-1.0),
    new Aluno(11,"Laura",9.8)
    };
    int numDiscentes = sizeof(discente)/sizeof(Aluno *);
    Turma *turma = new Turma(0,"SEM ALUNOS","INDEFINIDO");
    int a;
    cout << turma->str() << endl;
    turma->defineNumero(123);
    turma->defineDisciplina("Linguagem C");
    turma->defineProfessor("Alberto");
    
    for(a=0; a<5; ++a){
        if(!turma->adicionaAluno(discente[a])) { 
            cerr << "ERRO 1"; exit(1); 
        }
    }
    for(a=0; a<5; ++a){
        
        if(turma->obtemAluno(a) != discente[a]) { 
            cerr << "ERRO 2"; exit(1); 
            }
    }
    for(a=0; a<numDiscentes; a++){
        if(turma->obtemAluno(a) != nullptr) { 
            cerr << "ERRO 3"; exit(1); 
        }
    }    
    cout << turma->str() << endl;
    for(a=5; a<MAX_ALUNOS; a++){
        if(!turma->adicionaAluno(discente[a])) { 
            cerr << "ERRO 4"; exit(1); 
        }
    }
    for(a=0; a<numDiscentes; a++){
        if(turma->adicionaAluno(discente[a])) { 
            cerr << "ERRO 5"; exit(1); 
        }
    }
    for(a=0; a<MAX_ALUNOS; a++){
            if(turma->obtemAluno(a) != discente[a]) { 
                cerr << "ERRO 6"; exit(1); 
            }
    }        
    cout << turma->str() << endl;
    delete turma;
    for(int i = 0; i<numDiscentes; ++i){
        delete discente[i];
    }
    return 0;
}