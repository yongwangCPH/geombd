/*
# $Id: AD4.1_compact.dat,v 1.5 2012/03/15 15:55:57 rhuey Exp $
# 
# AutoDock 
# 
# Copyright (C) 1989-2007,  Garrett M. Morris, David S. Goodsell, Ruth Huey, Arthur J. Olson, 
# All Rights Reserved.
# 
# AutoDock is a Trade Mark of The Scripps Research Institute.
# 
# This program is free software; you can redistribute it and/or
# modify it under the terms of the GNU General Public License
# as published by the Free Software Foundation; either version 2
# of the License, or (at your option) any later version.
# 
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
# 
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software
# Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.

# AutoDock Linear Free Energy Model Coefficients and Energetic Parameters
#                   Version 4.1 Compact
#                     $Revision: 1.5 $

# FE_unbound_model is used to specify how the internal energy of the
# ligand should be treated when estimating the free energy of binding,
# and can be set to one of the following strings:
#   unbound_same_as_bound, extended, or compact
# unbound_same_as_bound -- this assumes the internal energy of the ligand is the
#                          same before and after binding.
# extended -- this assumes the internal energy of the ligand is that of an 
#             extended conformation when unbound.
# compact -- this assumes the internal energy of the ligand is that of a 
#            compact conformation when unbound.
#FE_unbound_model compact

# AutoDock 4 free energy coefficients with respect to original (AD2) energetic parameters
#  This model assumes that the unbound conformation is compact.
#  See Table 3 in Huey,Morris,Olson&Goodsell (2007) J Comput Chem 28: 1145-1152.
#
#               Free Energy Coefficient
#               ------
FE_coeff_vdW    0.1641
FE_coeff_hbond  0.0531
FE_coeff_estat  0.1272
FE_coeff_desolv 0.0603
FE_coeff_tors   0.2272

# AutoDock 4 Energy Parameters

# - Atomic solvation volumes and parameters
# - Unweighted vdW and Unweighted H-bond Well Depths
#
# - Atom Types
# - Rii = sum of vdW radii of two like atoms (in Angstrom)
# - epsii = vdW well depth (in Kcal/mol)
# - vol = atomic solvation volume (in Angstrom^3)
# - solpar = atomic solvation parameter
# - Rij_hb = H-bond radius of the heteroatom in contact with a hydrogen (in Angstrom)
# - epsij_hb = well depth of H-bond (in Kcal/mol)
# - hbond = integer indicating type of H-bonding atom (0=no H-bond)
# - rec_index = initialised to -1, but later on holds count of how many of this atom type are in receptor
# - map_index = initialised to -1, but later on holds the index of the AutoGrid map
# - bond_index = used in AutoDock to detect bonds; see "mdist.h", enum {C,N,O,H,XX,P,S}
#
# - To obtain the Rij value for non H-bonding atoms, calculate the 
#        arithmetic mean of the Rii values for the two atom types.
#        Rij = (Rii + Rjj) / 2
#
# - To obtain the epsij value for non H-bonding atoms, calculate the 
#        geometric mean of the epsii values for the two atom types.
#        epsij = sqrt( epsii * epsjj )
#
# - Note that the Rij_hb value is non-zero for heteroatoms only, and zero for H atoms;
#        to obtain the length of an H-bond, look up Rij_hb for the heteroatom only; 
#        this is combined with the Rii value for H in the receptor, in AutoGrid.
#        For example, the Rij_hb for OA-HD H-bonds will be (1.9 + 1.0) Angstrom, 
#        and the weighted epsij_hb will be 5.0 kcal/mol * FE_coeff_hbond.
#
#        Atom   Rii                             Rij_hb       rec_index
#        Type         epsii           solpar         epsij_hb    map_index
#                            vol                          hbond     bond_index
#        --     ----  -----  -------  --------  ---  ---  -  --  -- --
atom_par H      2.00  0.020   0.0000   0.00051  0.0  0.0  0  -1  -1  3	# Non H-bonding Hydrogen
atom_par HD     2.00  0.020   0.0000   0.00051  0.0  0.0  2  -1  -1  3	# Donor 1 H-bond Hydrogen
atom_par HS     2.00  0.020   0.0000   0.00051  0.0  0.0  1  -1  -1  3	# Donor S Spherical Hydrogen
atom_par C      4.00  0.150  33.5103  -0.00143  0.0  0.0  0  -1  -1  0	# Non H-bonding Aliphatic Carbon
atom_par A      4.00  0.150  33.5103  -0.00052  0.0  0.0  0  -1  -1  0	# Non H-bonding Aromatic Carbon
atom_par N      3.50  0.160  22.4493  -0.00162  0.0  0.0  0  -1  -1  1	# Non H-bonding Nitrogen
atom_par NA     3.50  0.160  22.4493  -0.00162  1.9  5.0  4  -1  -1  1	# Acceptor 1 H-bond Nitrogen
atom_par NS     3.50  0.160  22.4493  -0.00162  1.9  5.0  3  -1  -1  1	# Acceptor S Spherical Nitrogen
atom_par OA     3.20  0.200  17.1573  -0.00251  1.9  5.0  5  -1  -1  2	# Acceptor 2 H-bonds Oxygen
atom_par OS     3.20  0.200  17.1573  -0.00251  1.9  5.0  3  -1  -1  2	# Acceptor S Spherical Oxygen
atom_par F      3.09  0.080  15.4480  -0.00110  0.0  0.0  0  -1  -1  4	# Non H-bonding Fluorine
atom_par Mg     1.30  0.875   1.5600  -0.00110  0.0  0.0  0  -1  -1  4	# Non H-bonding Magnesium
atom_par MG     1.30  0.875   1.5600  -0.00110  0.0  0.0  0  -1  -1  4	# Non H-bonding Magnesium
atom_par P      4.20  0.200  38.7924  -0.00110  0.0  0.0  0  -1  -1  5	# Non H-bonding Phosphorus
atom_par SA     4.00  0.200  33.5103  -0.00214  2.5  1.0  5  -1  -1  6	# Acceptor 2 H-bonds Sulphur
atom_par S      4.00  0.200  33.5103  -0.00214  0.0  0.0  0  -1  -1  6	# Non H-bonding Sulphur
atom_par Cl     4.09  0.276  35.8235  -0.00110  0.0  0.0  0  -1  -1  4	# Non H-bonding Chlorine
atom_par CL     4.09  0.276  35.8235  -0.00110  0.0  0.0  0  -1  -1  4	# Non H-bonding Chlorine
atom_par Ca     1.98  0.550   2.7700  -0.00110  0.0  0.0  0  -1  -1  4	# Non H-bonding Calcium
atom_par CA     1.98  0.550   2.7700  -0.00110  0.0  0.0  0  -1  -1  4	# Non H-bonding Calcium
atom_par Mn     1.30  0.875   2.1400  -0.00110  0.0  0.0  0  -1  -1  4	# Non H-bonding Manganese
atom_par MN     1.30  0.875   2.1400  -0.00110  0.0  0.0  0  -1  -1  4	# Non H-bonding Manganese
atom_par Fe     1.30  0.010   1.8400  -0.00110  0.0  0.0  0  -1  -1  4	# Non H-bonding Iron
atom_par FE     1.30  0.010   1.8400  -0.00110  0.0  0.0  0  -1  -1  4	# Non H-bonding Iron
atom_par Zn     1.48  0.550   1.7000  -0.00110  0.0  0.0  0  -1  -1  4	# Non H-bonding Zinc
atom_par ZN     1.48  0.550   1.7000  -0.00110  0.0  0.0  0  -1  -1  4	# Non H-bonding Zinc
atom_par Br     4.33  0.389  42.5661  -0.00110  0.0  0.0  0  -1  -1  4	# Non H-bonding Bromine
atom_par BR     4.33  0.389  42.5661  -0.00110  0.0  0.0  0  -1  -1  4	# Non H-bonding Bromine
atom_par I      4.72  0.550  55.0585  -0.00110  0.0  0.0  0  -1  -1  4	# Non H-bonding Iodine
atom_par Z      4.00  0.150  33.5103  -0.00143  0.0  0.0  0  -1  -1  0  # Non H-bonding covalent map
atom_par G      4.00  0.150  33.5103  -0.00143  0.0  0.0  0  -1  -1  0	# Ring closure Glue Aliphatic Carbon  # SF
atom_par GA     4.00  0.150  33.5103  -0.00052  0.0  0.0  0  -1  -1  0	# Ring closure Glue Aromatic Carbon   # SF
atom_par J      4.00  0.150  33.5103  -0.00143  0.0  0.0  0  -1  -1  0	# Ring closure Glue Aliphatic Carbon  # SF
atom_par Q      4.00  0.150  33.5103  -0.00143  0.0  0.0  0  -1  -1  0	# Ring closure Glue Aliphatic Carbon  # SF
*/

#include <vector>
#include <set>
#include <fstream>
#include <iostream>
#include <string>
using namespace std;


struct pair_parameter {
  double A;
  double B;
  int xB;
};

typedef vector<pair_parameter> Vec;
typedef vector<Vec> PairMap;


class AutoDockParameters {
  public:
    /*
    double w_vdw;
    double w_hbond;
    double w_elec;
    double w_desolv;
    */

    vector<string> types;
    vector<double> Rii;
    vector<double> epsii;
    /*
    vector<double> vol;
    vector<double> solpar;
    vector<double> Rij_hb;
    vector<double> epsij_hb;
    vector<int> hbond_type;
    */

    PairMap lj_map;

  public:
    AutoDockParameters(string filename) {
      string line, token;
      ifstream fd;

      fd.open(filename.c_str(), ifstream::in);
      while(getline(fd, line)) {
        if(line[0] == '#') continue;
        parseNextValue(&line, &token);

        if(token.length() > 2) {
          // free energy weights
          /*
          if(token.substr(0, 2) == "FE") {
            char weight_type = token.substr(9, 1)[0];
            parseNextValue(&line, &token);
            double value = stringToDouble(token);
            switch(weight_type) {
              case 'v':
                w_vdw = value;
                break;
              case 'h':
                w_hbond = value;
                break;
              case 'e':
                w_elec = value;
                break;
              case 'd':
                w_desolv = value;
                break;
            }
          }
          */
          // everything else
          if(token == "atom_par") {
            parseNextValue(&line, &token);
            types.push_back(token);
            parseNextValue(&line, &token);
            Rii.push_back(stringToDouble(token));
            parseNextValue(&line, &token);
            epsii.push_back(stringToDouble(token));
            /*
            parseNextValue(&line, &token);
            vol.push_back(stringToDouble(token));
            parseNextValue(&line, &token);
            solpar.push_back(stringToDouble(token));
            parseNextValue(&line, &token);
            Rij_hb.push_back(stringToDouble(token));
            parseNextValue(&line, &token);
            epsij_hb.push_back(stringToDouble(token));
            parseNextValue(&line, &token);
            hbond_type.push_back(stringToInt(token));
            */
          }
        }
      }

      lj_map = PairMap(types.size());

      for(int i=0; i < types.size(); i++) {
        for(int j=0; j < i+1; j++) {
          pair_parameter parm;

          double rij = 0.5 * (Rii[i] + Rii[j]);
          double eij = sqrt(epsii[i] * epsii[j]);
          parm = {
            /*A*/4. * eij * pow(rij, 12),
            /*B*/4. * eij * pow(rij, 6),
            /*xB*/ (int)6
          };

          lj_map[i].push_back(parm);
        }
      }
    }

    int index_for_type(string type) {
      for(int i=0; i < types.size(); i++) {
        if(types[i] == type) return i;
      }
      cout << "* Warning: AutoDockParameters::index_for_type returning -1" << endl;
      return -1;
    }


};


class LigandPDBQT {
  public:
    set<string> types_set;

  public:
    LigandPDBQT(string filename) {
      string line, token;
      ifstream fd;

      fd.open(filename.c_str(), ifstream::in);
      while(getline(fd, line)) {
        if(line[0] == '#') continue;
        if(line.substr(0, 4) == "ATOM") {
          string t = line.substr(77, 2);
          string tt = rtrim(t);
          types_set.insert(tt);
        }
      }
    }
};



class ReceptorPDBQT {
  public:
    vector<vertex> coordinates;
    vertex center;
    vertex max;
    vertex min;
    vector<int> types;
    set<string> types_set;
    vector<double> charges;

  public:
    ReceptorPDBQT(string filename, AutoDockParameters *adp) {
      string line, token;
      ifstream fd;

      center.x = center.y = center.z = 0.;
      max.x = max.y = max.z = -1e9;
      min.x = min.y = min.z =  1e9;

      fd.open(filename.c_str(), ifstream::in);
      while(getline(fd, line)) {
        if(line[0] == '#') continue;
        if(line.substr(0, 4) == "ATOM" or line.substr(0, 6) == "HETATM") {
          // coordinates
          vertex R;
          R.x = stringToDouble(line.substr(30, 8));
          R.y = stringToDouble(line.substr(38, 8));
          R.z = stringToDouble(line.substr(46, 8));
          coordinates.push_back(R);
          center.x += R.x;
          center.y += R.y;
          center.z += R.z;
          if(R.x > max.x) max.x = R.x;
          if(R.y > max.y) max.y = R.y;
          if(R.z > max.z) max.z = R.z;
          if(R.x < min.x) min.x = R.x;
          if(R.y < min.y) min.y = R.y;
          if(R.z < min.z) min.z = R.z;
          // type
          string t = line.substr(77, 2);
          string tt = rtrim(t);
          if(adp)
            types.push_back(adp->index_for_type(tt));
          types_set.insert(tt);
          // charge
          double q = stringToDouble(line.substr(68, 8));
          charges.push_back(q);
        }
      }

      center.x /= coordinates.size();
      center.y /= coordinates.size();
      center.z /= coordinates.size();
    }
};
