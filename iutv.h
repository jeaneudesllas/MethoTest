/*! \file iutv.h
 *
 * Ce fichier contient quelques fonctions de conversion, une fonction retournant la taille d'une string et les bibliothèques nécessaires.
 *
 */

#include <cmath>     //Pour utiliser abs(float), abs(double), etc
#include <iostream>  //Pour cin et cout
#include <string>    //Pour les strings
#include <cstdlib>   //Pour utiliser abs(int)
#include <sstream>   //Pour les conversions string/nombre
#include <cctype>    //Pour utiliser tolower et toupper
#include <algorithm> //Pour utiliser transform

using namespace std;


/*!
 * \fn int size(string s)
 *
 * Fonction retournant le nombre de caractères d'un string
 */
int size(string s)
{
    return s.size();
}

/*!
 * \fn int string2int(string s)
 *
 *  Transforme une chaîne de caractères en un entier
 *  \param s : chaîne de caractères
 */
int string2int(string s)
{
    int tmp;
    stringstream st;
    st << s;
    st >> tmp;
    return tmp;
}


/*!
 * \fn float string2float(string s)
 *
 * Transforme une chaîne de caractères en un nombre flottant
 *
 * \param s : chaîne de caractères
 */
float string2float(string s)
{
    float tmp;
    stringstream st;
    st << s;
    st >> tmp;
    return tmp;
}

/*!
 *  \fn double string2double(string s)
 *
 *  Transforme une chaîne de caractères en un nombre flottant double précision
 *
 *  \param s : chaîne de caractères
 */
double string2double(string s)
{
    float tmp;
    stringstream st;
    st << s;
    st >> tmp;
    return tmp;
}

/*!
 *  \fn string float2string(float f)
 *  Transforme un nombre flottant en une chaîne de caractères
 *
 *  \param f : nombre flottant
 */
string float2string(float f)
{
    ostringstream os;
    os << f;
    return os.str();
}

/*!
 *  \fn string double2string(double f)
 *
 *  Transforme un nombre flottant double précision en une chaîne de caractères
 *
 *  \param f : nombre flottant double précision
 */
string double2string(double f)
{
    ostringstream os;
    os << f;
    return os.str();
}


/*!
 *  \fn string int2string(int f)
 *
 *  Transforme un nombre entier en une chaîne de caractères
 *
 *  \param f : nombre entier
 */
string int2string(int f)
{
    ostringstream os;
    os << f;
    return os.str();
}

//Pour la conversion minuscules/majuscules
struct my_tolower
{
    char operator()(char c) const
    {
        return std::tolower(static_cast<unsigned char>(c));
    }
};

struct my_toupper
{
    char operator()(char c) const
    {
        return std::toupper(static_cast<unsigned char>(c));
    }
};

/*!
 *  \fn string lower(string s)
 *
 *  Retourne la chaîne de caractères passée en paramètre en lettres minuscules
 *
 *  \param s : chaîne de caractères
 */
string lower(string s)
{
    string tmp = s;
    std::transform(tmp.begin(), tmp.end(), tmp.begin(), my_tolower());
    return tmp;
}

/*!
 *  \fn string upper(string s)
 *
 *  Retourne la chaîne de caractères passée en paramètre en lettres majuscules
 *
 *  \param s : chaîne de caractères
 */
string upper(string s)
{
    string tmp = s;
    std::transform(tmp.begin(), tmp.end(), tmp.begin(), my_toupper());
    return tmp;
}

/*!
 *  \fn char lower(char c)
 *
 *  Retourne le caractère minuscule associé au caractère passé en paramètre
 *
 *  \param c : caractère
 */
char lower(char c)
{
    return tolower(c);//Car tolower retourne un int, pas un char (donc pour l'affichage d'un caractère, il faut un cast)
}

/*!
 *  \fn char upper(char c)
 *
 *  Retourne le caractère majuscule associé au caractère passé en paramètre
 *
 *  \param c : caractère
 */
char upper(char c)
{
    return toupper(c);//Idem, toupper renvoit un int
}


/*!
 * \fn string rjust(string s, int n)
 *
 * Permet de faire un affichage justifié à droite
 *
 * \param s : chaîne de caractères
 * \param n : nombre de caractères alloué à la chaîne de caractères justifiée
 */
string rjust(string s, int n){
    int tailleS = size(s);

    int nb = n-tailleS;
    string ch = "";
    while (nb--){
        ch = ch + " ";
    }
     ch = ch+ s;

    return ch;
}
