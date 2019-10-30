class Aluno

end

class Professor
  def ensina(aluno)
    def aluno.programar
      "sabe programar"
    end
  end
end

bruno = Aluno.new
resposta = bruno.respond_to? :programar
puts resposta

professor = Professor.new
professor.ensina bruno
resposta = bruno.programar
puts resposta
