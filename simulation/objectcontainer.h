#ifndef OBJECTCONTAINER_H
#define OBJECTCONTAINER_H

#include "object.h"
#include "types.h"
#include <vector>

namespace simulation {

/**
   * @brief Eine Basisklasse, für alle Klassen, die mehrere Objekte enthalten.
   *Beinhaltet Methoden, zum Hinzufügen und Entfernen von Objekten, sowie zum Prüfen, ob ein Objekt vorhanden ist.
   */
class ObjectContainer {
public:
  ObjectContainer();
  virtual ~ObjectContainer();

  /**
   *Methode, um ein Objekt hinzuzufügen.
   *@param newobject Der Pointer des hinzuzufügenden Objekts.
   */
  void AddObject(Object* newobject);

  /**
   *Methode, um zu prüfen, ob ein Objekt bereits vorhanden ist.
   *@param object Der Pointer des Objekts, nachdem gesucht werden soll.
   *@return true, wenn das Objekt enthalten ist, sonst false.
   */
  bool Contains(Object* object);

  /**
   *Methode, um ein Objekt aus der Liste zu entferen.
   *Steht das Objekt nicht in der Liste, so wird nichts unternommen.
   *@param object Der Pointer des Objekts, welches entfernt werden soll.
   */
  void RemoveObject(Object* object);
protected:
  /**
   *Die interne Objektliste, zum Speichern der Pointer der hinzugefügten Objekte.
   */
  std::vector<Object*> Objects;

};

}

#endif // OBJECTCONTAINER_H
