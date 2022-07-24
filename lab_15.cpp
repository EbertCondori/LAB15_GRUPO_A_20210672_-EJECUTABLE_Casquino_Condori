#include "iostream"
#include "vector"
using namespace std;
class Carros {
public:
	std::vector<std::string> componentes;
	void ListaComponentes()const {
		std::cout << "Componentes : ";
		for (size_t i = 0; i < componentes.size(); i++) {
			if (componentes[i] == componentes.back()) {
				std::cout << componentes[i];
			}
			else {
				std::cout << componentes[i] << ", ";
			}
		}
		std::cout << "\n\n";
	}
};

class IBuilder {
public:
	virtual ~IBuilder() {}
	virtual void ProducirPuertas(string) const = 0;
	virtual void ProducirLlantas(string) const = 0;
	virtual void ProducirTimon(string) const = 0;
	virtual void ProducirAsientos(string) const = 0;
	virtual void ProducirMotor(string) const = 0;
	virtual void ProducirEspejos(string) const = 0;
	virtual void ProducirVidrios(string) const = 0;
	
};

class BuilderEspecifico : public IBuilder {
private:
	Carros* carro;
	string color;
public:
	BuilderEspecifico() {
		this->Reset();
	}
	~BuilderEspecifico() {
		delete carro;
	}
	void Reset() {
		this->carro = new Carros();
	}
	void ProducirPuertas(string color)const override {
		string a="Puerta ";
		this->carro->componentes.push_back(a+color);
	}
	void ProducirLlantas(string color)const override {
		string a="Llantas ";
		this->carro->componentes.push_back(a+color);
	}
	void ProducirTimon(string color)const override {
		string a="Timon ";
		this->carro->componentes.push_back(a+color);
	}
	void ProducirAsientos(string color)const override {
		string a="Asientos ";
		this->carro->componentes.push_back(a+color);
	}
	void ProducirMotor(string color)const override {
		string a="LlMotorantas ";
		this->carro->componentes.push_back(a+color);
	}
	void ProducirEspejos(string color)const override {
		string a="Espejos ";
		this->carro->componentes.push_back(a+color);
	}
	void ProducirVidrios(string color)const override {
		string a="Vidrios ";
		this->carro->componentes.push_back(a+color);
	}
	
	//(puertas, llantas, timón, asientos, motor, espejos, vidrios,
	
	Carros* GetProducto() {
		Carros* resultado = this->carro;
		this->Reset();
		return resultado;
	}
};

class Director {
private:
	IBuilder* builder;
public:
	void set_builder(IBuilder* builder) {
		this->builder = builder;
	}
	void BuildProductoMin() {
		this->builder->ProducirTimon("verde");
		this->builder->ProducirLlantas("negra");
		this->builder->ProducirMotor("cafe");
		
	}
	void BuildProductoCompleto() {
		this->builder->ProducirPuertas("roja");
		this->builder->ProducirLlantas("blanca");
		this->builder->ProducirTimon("morado");
		this->builder->ProducirAsientos("negro");
		this->builder->ProducirMotor("azul");
		this->builder->ProducirEspejos("naranja");
		this->builder->ProducirVidrios("cafe");
		
	}
};

void ClienteCode(Director& director)
{
	BuilderEspecifico* builder = new BuilderEspecifico();
	director.set_builder(builder);
	std::cout << "Carro obejtos Basico:\n";
	director.BuildProductoMin();
	Carros* p = builder->GetProducto();
	p->ListaComponentes();
	delete p;
	std::cout << "Carro completo Completo:\n";
	director.BuildProductoCompleto();
	p = builder->GetProducto();
	p->ListaComponentes();
	delete p;
	std::cout << "Carro 1 pesonalizado :\n";
	builder->ProducirPuertas("verde");
	builder->ProducirTimon("cafe");
	p = builder->GetProducto();
	p->ListaComponentes();
	delete p;
	
	std::cout << "Carro 2 pesonalizado :\n";
	builder->ProducirAsientos("morado");
	builder->ProducirVidrios("azul");
	builder->ProducirMotor("blanco");
	p = builder->GetProducto();
	p->ListaComponentes();
	delete p;
	
	
	delete builder;
}


int main() {
	Director* director = new Director();
	ClienteCode(*director);
	delete director;
	return 0;
}
