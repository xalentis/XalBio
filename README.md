# XalBio

XalBio contains a number of routines to one-hot encode a DNA sequence into a matrix for use in R with the Keras library.

Installation:
devtools::install_github("https://github.com/xalentis/XalBio")

Usage:
library(XalBio)

sequence <- 'AGCTN'
base <- 'G'

one_hot <- encode_base(base)

reversed <- reverse_compliment(sequence)

# encode sequence and reverse compliment, with a gap of 48 N bases in-between
one_hot <- encode_sequence(sequence, reversed, 48)
