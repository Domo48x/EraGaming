clear all
close all
clc

L1=Link([pi/2 0 2 0 0 0]); %Eslab�n 1
L2=Link([0 2 0 0 0 0]); %Eslab�n 0
        
scara = SerialLink([L1 L2],'name','ROBOT 3 ARTICULACIONES');
scara.plot([0 0])
scara.teach