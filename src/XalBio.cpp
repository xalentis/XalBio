#include <Rcpp.h>

using namespace Rcpp;

//' One-hot encodes a DNA base
//'
//' @param base A,T,C,G or N
//' @return A one-hot encoded vector
// [[Rcpp::export]]
NumericVector encode_base(char base) {
  NumericVector map (4);
  if (base == 'A')
  {
    map[0] = 1;
  }
  if (base == 'T')
  {
    map[1] = 1;
  }
  if (base == 'G')
  {
    map[2] = 1;
  }
  if (base == 'C')
  {
    map[3] = 1;
  }
  map.attr("dim") = Dimension(1,4);
  return map;
}

//' One-hot encodes a DNA sequence
//'
//' @param DNA sequence of A,T,C,G or N bases
//' @return A one-hot encoded vector
// [[Rcpp::export]]
NumericVector encode_sequence(CharacterVector sequence, CharacterVector reverse, int gap) {
  
  int num_bases = sequence[0].size();
  NumericVector result (4 * ((num_bases * 2) + gap));
  
  int j=0;
  for( int i=0; i < num_bases; i++ ) {
    NumericVector temp = encode_base(sequence[0][i]);
    result[j] = temp[0];
    result[j+5] = temp[1];
    result[j+10] = temp[2];
    result[j+15] = temp[3];
    j++;
  }
  j+=4;
  for( int i=0; i <= gap; i++ ) {
    result[j] = 0;
    result[j+5] = 0;
    result[j+10] = 0;
    result[j+15] = 0;
    j++;
  }
  j+=4;
  for( int i=0; i < num_bases; i++ ) {
    NumericVector temp = encode_base(reverse[0][i]);
    result[j] = temp[0];
    result[j+5] = temp[1];
    result[j+10] = temp[2];
    result[j+15] = temp[3];
    j++;
  }
  result.attr("dim") = Dimension(num_bases*2+gap,4);
  
  return result;
}

//' Generates reverse-compliment of DNA sequence
//'
//' @param DNA sequence of A,T,C,G or N bases
//' @return Reverse-compliment of sequence
// [[Rcpp::export]]
String reverse_compliment(CharacterVector sequence) {
  int num_bases = sequence[0].size();
  String result = "";
  
  for( int i=num_bases; i >= 0; i-- ) {
    if (sequence[0][i] == 'A') {result += "T";}
    if (sequence[0][i] == 'C') {result += "G";}
    if (sequence[0][i] == 'G') {result += "C";}
    if (sequence[0][i] == 'T') {result += "A";}
    if (sequence[0][i] == 'N') {result += "N";}
  }

  return result;
}
