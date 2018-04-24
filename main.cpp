/*!
 * \file main.cpp
 */
#include <iostream>
#include <string>
#include <gtkmm/comboboxtext.h>
#include <gtkmm/label.h>
#include <gtkmm/main.h>
#include <gtkmm/table.h>
#include <gtkmm/box.h>
#include <gtkmm/window.h>
#include "grille.hpp"

using namespace std;

Gtk::ComboBoxText* choix[10];
Gtk::Label* gir;
string chaineGIR;

void calcul();

int calculSomme(int c);
int calculModalite(int variable);
int calculGIR(int rang);

void configurerComboBox(Gtk::ComboBoxText &combo);

int main(int argc, char** argv){

  Gtk::Main app(argc,argv);
  Gtk::Window fenetre;
  
  fenetre.set_title("Calculateur AGGIR");
  fenetre.set_position(Gtk::WIN_POS_CENTER);
  fenetre.set_default_size(480,360);

  Gtk::VBox boite;
  fenetre.add(boite);
  
  Gtk::Table table(Grille::NOMBRE_VARIABLE+1,2,false);
  boite.pack_start(table);

  for(int i = 0 ; i < 10 ; i++){
    choix[i] = Gtk::manage(new Gtk::ComboBoxText());
    configurerComboBox(*choix[i]);
    table.attach(*choix[i],1,2,i,i+1);
  }
 
  {
    Gtk::Label *label = Gtk::manage(new Gtk::Label("Cohérence"));
    table.attach(*label,0,1,0,1);
  }
  {
    Gtk::Label *label = Gtk::manage(new Gtk::Label("Orientation"));
    table.attach(*label,0,1,1,2);
  }
  {
    Gtk::Label *label = Gtk::manage(new Gtk::Label("Toilette"));
    table.attach(*label,0,1,2,3);
  }
  {
    Gtk::Label *label = Gtk::manage(new Gtk::Label("Habillage"));
    table.attach(*label,0,1,3,4);
  }
  {
    Gtk::Label *label = Gtk::manage(new Gtk::Label("Alimentation"));
    table.attach(*label,0,1,4,5);
  }
  {
    Gtk::Label *label = Gtk::manage(new Gtk::Label("Elimination"));
    table.attach(*label,0,1,5,6);
  }
  {
    Gtk::Label *label = Gtk::manage(new Gtk::Label("Transfert"));
    table.attach(*label,0,1,6,7);
  }
  {
    Gtk::Label *label = Gtk::manage(new Gtk::Label("Déplacement intérieur"));
    table.attach(*label,0,1,7,8);
  }
  {
    Gtk::Label *label = Gtk::manage(new Gtk::Label("Déplacement extérieur"));
    table.attach(*label,0,1,8,9);
  }
  {
    Gtk::Label *label = Gtk::manage(new Gtk::Label("Communication"));
    table.attach(*label,0,1,9,10);
  }


  Gtk::HBox resultat;
  boite.pack_start(resultat);
  Gtk::Label label("GIR : ");
  resultat.pack_start(label);
  gir = Gtk::manage(new Gtk::Label("Niveau non déterminé"));
  resultat.pack_start(*gir);
  Gtk::Button boutonCalcul("Calculer GIR");
  resultat.pack_end(boutonCalcul);
  boutonCalcul.signal_clicked().connect(sigc::ptr_fun(&calcul));

  fenetre.show_all();
  
  Gtk::Main::run(fenetre);
  return 0;

}

void configurerComboBox(Gtk::ComboBoxText &combo){
  combo.append("Modalité A");
  combo.append("Modalité B");
  combo.append("Modalité C");
  combo.set_active_text("Modalité A");
}

void calcul(){

  for(int i = 0 ; i < Grille::NOMBRE_RANG ; i++){

    if(Grille::rangs[i][1] <= calculSomme(Grille::rangs[i][0])){
      chaineGIR.clear();
      chaineGIR += ((char) 48 + calculGIR(i));
      gir->set_text(chaineGIR);
      break;
    }

  }

}

int calculSomme(int c){

  int somme = 0;
  for(int i = 0 ; i < Grille::NOMBRE_VARIABLE ; i++){
    somme += Grille::valeurs[c][calculModalite(i)][i];
  }
  return somme;

}

int calculModalite(int variable){

  if(choix[variable]->get_active_text() == string("Modalité B")){
    return Grille::ModaliteB;
  } else if(choix[variable]->get_active_text() == string("Modalité C")){
    return Grille::ModaliteC;
  } else {
    return Grille::ModaliteA;
  }

}

int calculGIR(int rang){

  for(int i = 0 ; i < Grille::NOMBRE_GIR ; i++){
    if(rang <= Grille::gir[i]){
      return i+1;
    }
  }
  return -1;

}
