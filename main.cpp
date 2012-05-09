#include <vtkSmartPointer.h>
#include <vtkSphereSource.h>
#include <vtkXMLPolyDataWriter.h>

#include "vtkStratifiedSampling.h"

int main(int argc, char *argv[])
{
  vtkSmartPointer<vtkSphereSource> sphereSource = 
    vtkSmartPointer<vtkSphereSource>::New();
  sphereSource->Update();

  vtkSmartPointer<vtkStratifiedSampling> stratifiedSampling = 
    vtkSmartPointer<vtkStratifiedSampling>::New();
  stratifiedSampling->SetInputData(sphereSource->GetOutput());
  stratifiedSampling->Update();
  
  vtkSmartPointer<vtkXMLPolyDataWriter> writer = 
      vtkSmartPointer<vtkXMLPolyDataWriter>::New();
  writer->SetInputData(stratifiedSampling->GetOutput());
  writer->SetFileName("test.vtp");
  writer->Write();

  return EXIT_SUCCESS;
}
