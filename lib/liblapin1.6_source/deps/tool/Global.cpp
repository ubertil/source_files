// Jason Brillante "Damdoshi"
// Lisa Monpierre "Leeza"
// Pentacle Technologie 2009-2014
//
// DABSIC
// Developer's All-purpose Block Structured Instruction Code

#include		"ParsingTools.hpp"

const bpt::string	bpt::ParsingTools::FieldNameFirstChar =
  WCP"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ_"
  ;

const bpt::string	bpt::ParsingTools::FieldName =
  WCP"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789_"
  ;

const bpt::string	bpt::ParsingTools::Teal =
  WCP"\033[1;36m"
 ;

const bpt::string	bpt::ParsingTools::Blue =
  WCP"\033[1;34m"
  ;

const bpt::string	bpt::ParsingTools::Red =
  WCP"\033[1;31m"
  ;

const bpt::string	bpt::ParsingTools::Green =
  WCP"\033[1;32m"
  ;

const bpt::string	bpt::ParsingTools::Purple =
  WCP"\033[0;35m"
  ;

const bpt::string	bpt::ParsingTools::Pink =
  WCP"\033[1;35m"
  ;

const bpt::string	bpt::ParsingTools::Yellow =
  WCP"\033[1;33m"
  ;

const bpt::string	bpt::ParsingTools::Grey =
  WCP"\033[1;30m"
  ;

const bpt::string	bpt::ParsingTools::BlackOnWhite =
  WCP"\033[0;30;47m"
  ;

const bpt::string	bpt::ParsingTools::White =
  WCP"\033[00m"
  ;

const bpt::string	bpt::ParsingTools::OpenSection = WCP"[";

const bpt::string	bpt::ParsingTools::CloseSection = WCP"]";

const bpt::string	bpt::ParsingTools::Address = WCP":";

const bpt::string	bpt::ParsingTools::Pointer = WCP"*";

const bpt::string	bpt::ParsingTools::PointerPrefix = WCP"#";

const bpt::string	bpt::ParsingTools::DescriptorPrefix = WCP"$";

const bpt::string	bpt::ParsingTools::TypePrefix = WCP"?";

const bpt::string	bpt::ParsingTools::NullPtr = WCP"NULL";

const bpt::string	bpt::ParsingTools::NullAddr[2] = 
  {
    WCP"Nowhere",
    WCP"Nullepart"
  };

const bpt::string	bpt::ParsingTools::Nothing[3] =
  {
    WCP"Nothing",
    WCP"Rien",
    WCP"Vide"
  };

const bpt::string	bpt::ParsingTools::Assignation[4] =
  {
    WCP"=",
    WCP":=",
    WCP"<=",
    WCP"<-"
  };

const bpt::string	bpt::ParsingTools::Include[2] =
  {
    WCP"Include",
    WCP"Inclure"
  };
const bpt::string	bpt::ParsingTools::IncludeCipher[2] =
  {
    WCP"Includec",
    WCP"Inclurec"
  };
const bpt::string	bpt::ParsingTools::Message[1] =
  {
    WCP"Message"
  };
const bpt::string	bpt::ParsingTools::Warning[2] =
  {
    WCP"Warning",
    WCP"Attention"
  };
const bpt::string	bpt::ParsingTools::ErrorD[2] =
  {
    WCP"Error",
    WCP"Erreur"
  };

const bpt::string	bpt::ParsingTools::Extern[1] =
  {
    WCP"extern"
  };

const bpt::string	bpt::ParsingTools::Local[1] =
  {
    WCP"local"
  };

const bpt::string	bpt::ParsingTools::Private[2] =
  {
    WCP"private",
    WCP"privé"
  };

const bpt::string	bpt::ParsingTools::Protected[2] =
  {
    WCP"protected",
    WCP"protégé"
  };

const bpt::string	bpt::ParsingTools::Locked[2] =
  {
    WCP"locked",
    WCP"verrouillé"
  };

const bpt::string	bpt::ParsingTools::Public[2] =
  {
    WCP"public",
    WCP"publique"
  };

const bpt::string	bpt::ParsingTools::Limited[2] =
  {
    WCP"limited",
    WCP"limité"
  };

const bpt::string	bpt::ParsingTools::Strict[1] =
  {
    WCP"strict"
  };

const bpt::string	bpt::ParsingTools::Restricted[2] =
  {
    WCP"restricted",
    WCP"restreint"
  };

const bpt::string	bpt::ParsingTools::Const[2] =
  {
    WCP"const",
    WCP"solid"
  };

const bpt::string	bpt::ParsingTools::HexaPrefix = WCP"0x";
const bpt::string	bpt::ParsingTools::Hexadecimal = WCP"0123456789abcdef";

const bpt::string	bpt::ParsingTools::DecimalPrefix = WCP"";
const bpt::string	bpt::ParsingTools::Decimal = WCP"0123456789";

const bpt::string	bpt::ParsingTools::OctalPrefix = WCP"0";
const bpt::string	bpt::ParsingTools::Octal = WCP"01234567";

const bpt::string	bpt::ParsingTools::BinPrefix = WCP"0b";
const bpt::string	bpt::ParsingTools::Binary = WCP"01";

const bpt::string	bpt::ParsingTools::DabsicRoot = WCP"[]";
const bpt::string	bpt::ParsingTools::CurrentNode = "{}";
const bpt::string	bpt::ParsingTools::GetAddress = WCP"&";

const bpt::string	bpt::ParsingTools::Variant[3] =
  {
    WCP"variant",
    WCP"void",
    WCP"variable"
  };

const bpt::string	bpt::ParsingTools::Boolean[3] =
  {
    WCP"boolean",
    WCP"booléen",
    WCP"bool"
  };

const bpt::string	bpt::ParsingTools::Integer[3] =
  {
    WCP"integer",
    WCP"int",
    WCP"entier"
  };

const bpt::string	bpt::ParsingTools::Real[3] =
  {
    WCP"double",
    WCP"real",
    WCP"réel"
  };

const bpt::string	bpt::ParsingTools::Character[3] =
  {
    WCP"character",
    WCP"char",
    WCP"charactère"
  };

const bpt::string	bpt::ParsingTools::String[2] =
  {
    WCP"string",
    WCP"chaine"
  };

const bpt::string	bpt::ParsingTools::Descriptor[2] =
  {
    WCP"descriptor",
    WCP"index"
  };

const bpt::string	bpt::ParsingTools::Type[1] =
  {
    WCP"type"
  };

const bpt::string	bpt::ParsingTools::Record[4] =
  {
    WCP"record",
    WCP"structure",
    WCP"struct",
    WCP"enregistrement"
  };

const bpt::string	bpt::ParsingTools::True[4] =
  {
    WCP"True",
    WCP"Yes",
    WCP"Vrai",
    WCP"Oui"
  };

const bpt::string	bpt::ParsingTools::False[4] =
  {
    WCP"False",
    WCP"Non",
    WCP"Faux",
    WCP"No"
  };

const bpt::string	bpt::ParsingTools::PreviousNode = WCP"_";
const bpt::string	bpt::ParsingTools::DirectAccess = WCP".";
const bpt::string	bpt::ParsingTools::AddressAccess = WCP"->";

const bpt::string	bpt::ParsingTools::RealComma = WCP".";
const bpt::string	bpt::ParsingTools::CharacterDelimiter = WCP"'";
const bpt::string	bpt::ParsingTools::StringDelimiter = WCP"\"";

const bpt::string	bpt::ParsingTools::OpenScript = WCP"[Script";
const bpt::string	bpt::ParsingTools::OpenSequence = WCP"[Sequence";
const bpt::string	bpt::ParsingTools::OpenData = WCP"[Collection";
const bpt::string	bpt::ParsingTools::OpenXML = WCP"[XML";
const bpt::string	bpt::ParsingTools::CloseScope = WCP"]";

const bpt::string	bpt::ParsingTools::Field[2] = {
  WCP"Field",
  WCP"Champ"
};
const bpt::string	bpt::ParsingTools::Collection[1] = {
  WCP"Collection"
};
const bpt::string	bpt::ParsingTools::Script[1] = {
  WCP"Script"
};
const bpt::string	bpt::ParsingTools::Sequence[1] = {
  WCP"Sequence"
};
const bpt::string	bpt::ParsingTools::XMLType[1] = {
  WCP"XML"
};

const bpt::string	bpt::ParsingTools::OpenPriority = WCP"(";
const bpt::string	bpt::ParsingTools::ClosePriority = WCP")";
const bpt::string	bpt::ParsingTools::DataLength[4] =
  {
    WCP"Byte",
    WCP"Short",
    WCP"Word",
    WCP"Long"
  };

const bpt::string	bpt::ParsingTools::Separator = WCP",";
