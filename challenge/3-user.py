#!/usr/bin/python3
"""
 User Model
"""
import hashlib
import uuid


class User():
    """
    User class
    """

    __password = None

    def __init__(self):
        self.id = str(uuid.uuid4())

    @property
    def password(self):
        return self.__password

    @password.setter
    def password(self, pwd):
        if pwd is None or type(pwd) is not str:
            self.__password = None
        else:
            # Ensure this is __password (double underscore)
            self.__password = hashlib.md5(pwd.encode()).hexdigest().lower()

    def is_valid_password(self, pwd):
        if pwd is None or type(pwd) is not str or self.__password is None:
            return False
        
        # Change .upper() to .lower() here
        return hashlib.md5(pwd.encode()).hexdigest().lower() == self.__password
