from django.shortcuts import render
from perfis.models import Perfil

def index(request):
    return render(request, 'index.html')

def exibir(request, perfil_id):

	perfil = Perfil()

	if perfil_id == '1':
		perfil = Perfil('Bruno Cesar Angst', 'bruno.angst@rede.ulbra.br', '997 056 168', 'Trabalho como Dev')

	return render(request, 'perfil.html', { "perfil" : perfil})
