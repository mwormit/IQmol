#ifndef IQMOL_CONFIGURATOR_MOLECULARORBITALS_H
#define IQMOL_CONFIGURATOR_MOLECULARORBITALS_H
/*******************************************************************************
         
  Copyright (C) 2011-2013 Andrew Gilbert
      
  This file is part of IQmol, a free molecular visualization program. See
  <http://iqmol.org> for more details.
         
  IQmol is free software: you can redistribute it and/or modify it under the
  terms of the GNU General Public License as published by the Free Software  
  Foundation, either version 3 of the License, or (at your option) any later  
  version.

  IQmol is distributed in the hope that it will be useful, but WITHOUT ANY
  WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
  FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more
  details.
      
  You should have received a copy of the GNU General Public License along
  with IQmol.  If not, see <http://www.gnu.org/licenses/>.
   
********************************************************************************/

#include "Configurator.h"
#include "ui_MolecularOrbitalsConfigurator.h"
#include "SurfaceInfo.h"


namespace IQmol {

namespace Layer {
   class MolecularOrbitals;
}

namespace Configurator {

   /// Dialog that allows the user to select orbitals (and densities) for plotting.
   class MolecularOrbitals : public Base {

      Q_OBJECT

      public:
         enum { Orbital, Density, SpinDiffDensity, SpinOnlyDensity };

         explicit MolecularOrbitals(Layer::MolecularOrbitals&);
         ~MolecularOrbitals() { }

      public Q_SLOTS:
         void init();

      Q_SIGNALS:
         void queueSurface(Data::SurfaceInfo const&);
         void calculateSurfaces();
         void clearQueue();

      private Q_SLOTS:
         void on_surfaceType_currentIndexChanged(int);
         void on_addToQueueButton_clicked(bool);
         void on_calculateButton_clicked(bool);
         void on_cancelButton_clicked(bool);
         void on_alphaRadio_clicked(bool) { updateOrbitalRange(m_nAlpha); }
         void on_betaRadio_clicked(bool)  { updateOrbitalRange(m_nBeta); }
         void on_positiveColorButton_clicked(bool);
         void on_negativeColorButton_clicked(bool);

      private:
         void enableOrbitalSelection(bool);
         void enableNegativeColor(bool);
         void enableSpin(bool);
         void updateOrbitalRange(int nElectrons);
         void updateOrbitalRange(int nElectrons, QComboBox*);
         void setPositiveColor(QColor const& color);
         void setNegativeColor(QColor const& color);

         Layer::MolecularOrbitals& m_molecularOrbitals;
         Ui::MolecularOrbitalsConfigurator m_molecularOrbitalsConfigurator;

         unsigned int m_nAlpha;
         unsigned int m_nBeta;
         unsigned int m_nOrbitals;
   };

} } // End namespace IQmol::Configurator

#endif
