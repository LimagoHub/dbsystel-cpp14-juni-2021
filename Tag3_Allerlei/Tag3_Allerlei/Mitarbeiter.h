#pragma once
#include <ostream>
#include <string>
#include <sstream>
#include <random>
#include <string>

class mitarbeiter
{

private:
	const std::string id = generate_hex(36);
    std::string vorname{"John"};
	
    std::string nachname{ "Doe" };

    double gehalt{ 1000.0 };
	
	static auto random_char() -> unsigned int
	{
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(0, 255);
        return dis(gen);
    }

	static auto generate_hex(const unsigned int len) -> std::string
	{
        std::stringstream ss;
        for (auto i = 0; i < len; i++) {
            const auto rc = random_char();
            std::stringstream hexstream;
            hexstream << std::hex << rc;
            auto hex = hexstream.str();
            ss << (hex.length() < 2 ? '0' + hex : hex);
        }
        return ss.str();
    }

public:
    mitarbeiter() = default;
    mitarbeiter(std::string vorname, std::string nachname, double gehalt):vorname(vorname),nachname(nachname),gehalt(gehalt){};


	std::string get_id() const
	{
		return id;
	}

	std::string get_vorname() const
	{
		return vorname;
	}

	void set_vorname(const std::string& vorname)
	{
		this->vorname = vorname;
	}

	std::string get_nachname() const
	{
		return nachname;
	}

	void set_nachname(const std::string& nachname)
	{
		this->nachname = nachname;
	}

	double get_gehalt() const
	{
		return gehalt;
	}

	void set_gehalt(const double gehalt)
	{
		this->gehalt = gehalt;
	}


	friend std::ostream& operator<<(std::ostream& os, const mitarbeiter& obj)
	{
		return os
			<< "id: " << obj.id
			<< " vorname: " << obj.vorname
			<< " nachname: " << obj.nachname
			<< " gehalt: " << obj.gehalt;
	}
};
